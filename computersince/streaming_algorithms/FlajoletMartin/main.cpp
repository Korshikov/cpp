/*#include <cstdio>
#include <functional>
#include <iostream>


using namespace std;



int main() {
    //FlajoletMartin<char> counter;
    //freopen("/home/delf/input.txt", "rt", stdin);
    //unsigned  result = counter.counter(cin);
    //cout << result;

    std::hash<int> hashFunction;
    for (int t = 0; t < 64; ++t) {
        cout << hashFunction(t) << endl;
    }

    hash<int> hasher;
    printf("%lu",hasher(1024));
    //cout << hasher(1337) << endl;

    return 0;
}*/

#include <boost/functional/hash.hpp>
#include <iostream>

int main()
{
    boost::hash<int> int_hash;

    std::size_t h = int_hash(1024);

    std::cout << h;

    return 0;
}
