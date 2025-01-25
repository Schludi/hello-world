#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

const size_t BUFFER_SIZE = 1024 * 1024; // 1 MB

void writeTest(const std::string& filename, size_t dataSize) {
    std::vector<char> buffer(BUFFER_SIZE, 'A');
    std::ofstream file(filename, std::ios::binary);

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < dataSize / BUFFER_SIZE; ++i) {
        file.write(buffer.data(), BUFFER_SIZE);
    }
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    file.close();

    std::chrono::duration<double> duration = end - start;
    double writeSpeed = dataSize / duration.count() / (1024 * 1024); // MB/s
    std::cout << "Write Speed: " << writeSpeed << " MB/s" << std::endl;
}

void readTest(const std::string& filename, size_t dataSize) {
    std::vector<char> buffer(BUFFER_SIZE);
    std::ifstream file(filename, std::ios::binary);

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    while (file.read(buffer.data(), BUFFER_SIZE)) {}
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    file.close();

    std::chrono::duration<double> duration = end - start;
    double readSpeed = dataSize / duration.count() / (1024 * 1024); // MB/s
    std::cout << "Read Speed: " << readSpeed << " MB/s" << std::endl;
}

int main() {
    std::cout << "Generiere 1 GByte Datei!" << std::endl;
    std::string filename = "testfile.bin";
    size_t dataSize = 1024 * 1024 * 1024; // 100 MB
    writeTest(filename, dataSize);
    readTest(filename, dataSize);

    // Delete the test file
    std::remove(filename.c_str());

    return 0;
}