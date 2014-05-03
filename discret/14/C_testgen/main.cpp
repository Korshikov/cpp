#include <fstream>

using namespace std;

int main() {
    ofstream out("crypto.in");

    out << "10000 200000 200000\n";
    for (int i = 0; i < 200000; i++) {
        out << (i * 21312 + 871) % 1237 << " "
            << (i * 98721 + 713) % 7901753 << "\n"
            << (i * 1237 + 98798) % 99123 << " "
            << (i * 19024 + 94181) % 8971 << "\n\n";
    }

    for (int i = 0; i < 200000; i++) {
        out << (i * 31271) % 100000 << " "
            << (i * 31271) % 100000 + 100000 << "\n";
    }

    return 0;
}
