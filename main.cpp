#include <iostream>
#include <filesystem>
#include "src/utils/argparse.h"
#include "./src/steganography/BaseSteganography.h"
#include "./src/steganography/PngStegano.h"
#include "./src/lua/LuaEngine.h"

int main(int argc, char *argv[]) {
    argparse::ArgumentParser parser("Steganography");
    parser.addArgument({"--img"}, "Image Path");
    parser.addArgument({"--insert"}, "insert string");
    parser.addArgument({"--out"}, "Output Image Path");
    parser.parseArgs(argc, argv);

    auto args = parser.parseArgs(argc, argv);

    if(args.get<std::string>("insert") != "") {
        std::cout << "Start insert------------------------------" << std::endl;
        std::string imgPath = args.get<std::string>("img");
        std::string outPath = args.get<std::string>("out");
        std::filesystem::copy(imgPath, outPath, std::filesystem::copy_options::overwrite_existing);
        PngStegano stegano;
        stegano.insert(outPath, args.get<std::string>("insert"));
        std::cout << "End   insert------------------------------" << std::endl;

        std::cout << "Start load------------------------------" << std::endl;
        std::vector<char> result = stegano.load(outPath);
        std::cout << std::string(result.begin(), result.end()) << std::endl;
        std::cout << "End       ------------------------------" << std::endl;
    }

    LuaEngine::getInstance();

    return 0;
}
