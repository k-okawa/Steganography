#include <iostream>
#include <filesystem>
#include "src/utils/argparse.h"
#include "./src/steganography/BaseSteganography.h"
#include "./src/steganography/PngStegano.h"
#include "./src/lua/LuaEngine.h"
#include "./src/utils/fileutil.h"

int main(int argc, char *argv[]) {
    argparse::ArgumentParser parser("Steganography");
    parser.addArgument({"--test"}, "Test case");
    parser.addArgument({"--img"}, "Image Path");
    parser.addArgument({"--str"}, "insert string");
    parser.addArgument({"--path"}, "file path");
    parser.addArgument({"--out"}, "Output Image Path");
    parser.parseArgs(argc, argv);

    auto args = parser.parseArgs(argc, argv);

    if(args.has("test") && args.get<std::string>("test") == "strInsert") {
        std::string imgPath = args.get<std::string>("img");
        std::string outPath = args.get<std::string>("out");
        std::filesystem::copy(imgPath, outPath, std::filesystem::copy_options::overwrite_existing);
        PngStegano stegano;
        stegano.insert(outPath, args.get<std::string>("str"));
        std::vector<char> result = stegano.load(outPath);
        std::cout << std::string(result.begin(), result.end()) << std::endl;
    } else if(args.has("test") && args.get<std::string>("test") == "lua") {
        std::string imgPath = args.get<std::string>("img");
        std::string outPath = args.get<std::string>("out");
        std::string luaPath = args.get<std::string>("path");
        std::filesystem::copy(imgPath, outPath, std::filesystem::copy_options::overwrite_existing);
        PngStegano stegano;
        auto bytes = FileUtil::read(luaPath);
        stegano.insert(outPath, std::string(bytes.begin(), bytes.end()));
        std::vector<char> result = stegano.load(outPath);

        std::cout << "----Load Script----" << std::endl;
        std::string luaScriptStr = std::string(result.begin(), result.end());
        std::cout << luaScriptStr  << std::endl;
        std::cout << "----Load Script----" << std::endl;

        std::cout << "----Call Func----" << std::endl;
        auto luaEngine = LuaEngine::getInstance();
        luaEngine->execString(luaScriptStr);
        luaEngine->execFunc("main");
    }

    return 0;
}