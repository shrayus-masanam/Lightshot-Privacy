#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    fs::path path = "/Applications/Lightshot Screenshot.app/Contents/MacOS/Lightshot Screenshot";
    std::fstream bin(path, std::ios::binary | std::ios::in | std::ios::out);

    if (!bin) {
        std::cerr << "\033[1;31mError: couldn't open file. Please ensure that this program is being ran as root and that your Lightshot app is located in /Applications/.\x1b[0m" << std::endl;
        return 1;
    }

    int binsize = static_cast<int>(fs::file_size(path));
    std::cout << "Reading " << binsize << " bytes" << std::endl;
    if (binsize != 382704) {
        std::cout << "\033[0;33mWarning: file does not appear to be the correct size. You may be using a different version of Lightshot. This program may not work.\x1b[0m" << std::endl;
    }

    // replacing bytes from 0x002D82A to 0x002D846
    
    // seeking to the beginning of the file and then to the offset (our initial position)
    bin.seekg(0x2D82A, std::ios::beg);
    
    // writing the new bytes to the file
    const char new_bytes[] = {0x3A, 0x2F, 0x2F, 0x30, 0x2E, 0x30, 0x2E, 0x30, 0x2E, 0x30, 0x3A, 0x33, 0x30, 0x30, 0x30, 0x2F}; // ://0.0.0.0:3000/
    bin.write(new_bytes, sizeof(new_bytes));
    std::cout << "\033[1;32mDone. Wrote " << sizeof(new_bytes) << " bytes.\x1b[0m" << std::endl;
    return 0;
}