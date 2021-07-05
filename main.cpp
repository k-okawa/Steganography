#include <iostream>
#include <filesystem>
#include "src/utils/argparse.h"
#include "./src/steganography/ISteganography.h"
#include "./src/steganography/JpgStegano.h"

int main(int argc, char *argv[]) {
    argparse::ArgumentParser parser("Steganography");
    parser.addArgument({"--img"}, "Image Path");
    parser.addArgument({"--insert"}, "insert string");
    parser.addArgument({"--out"}, "Output Image Path");
    parser.parseArgs(argc, argv);

    auto args = parser.parseArgs(argc, argv);

    if(args.get<std::string>("insert") != "") {
        std::cout << "Start Insert------------------------------" << std::endl;
        std::string imgPath = args.get<std::string>("img");
        std::string outPath = args.get<std::string>("out");
        std::filesystem::copy(imgPath, outPath, std::filesystem::copy_options::overwrite_existing);
        JpgStegano stegano;
        stegano.Insert(outPath, args.get<std::string>("insert"));
        std::cout << "End   Insert------------------------------" << std::endl;
    }

    return 0;
}
