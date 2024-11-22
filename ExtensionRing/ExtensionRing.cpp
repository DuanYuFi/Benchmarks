/*
Benchmark on Z_{2^L}[X] / f(X)
with f = x^128 + x^7 + x^2 + x + 1
*/

#include <iostream>
#include <chrono>
#include <NTL/lzz_pX.h>
#include <NTL/ZZ_pX.h>

using namespace NTL;
using namespace std;

ZZ_pX modulo_poly;
const int L = 64;
const int module_coefs[] = {128, 7, 2, 1, 0};

const size_t TEST_SIZE = 10000;

inline ZZ_pX reduce(const ZZ_pX &f) {
    /*
    Here we use a trivial trick to reduce the polynomial f. 
    Since all the cofficients in modulo_poly are 0 or 1, so 
    we can use simple substractions instead of using the 
    expensive division operations. 
    */

    ZZ_pX f_copy = f;

    int degree = deg(f_copy);
    for (int i = degree; i >= 128; i --) {
        f_copy[i - 121] -= f_copy[i];
        f_copy[i - 126] -= f_copy[i];
        f_copy[i - 127] -= f_copy[i];
        f_copy[i - 128] -= f_copy[i];
        f_copy[i] = 0;
    }
    return f_copy;
}

void mul_test(ZZ_pX *results, ZZ_pX *a, ZZ_pX *b, size_t size) {
    // batch multiplication
    for (size_t i = 0; i < size; i++) {
        results[i] = reduce(a[i] * b[i]);
    }
}


int main() {
    if (L <= 60) {
        cout << "To obtain the best performance, you can use Extension Ring Small program when L <= 60" << endl;
    }
    
    ZZ_p::init(power2_ZZ(L));

    for (int i = 0; i < 5; i++) {
        SetCoeff(modulo_poly, module_coefs[i]);
    }

    ZZ_pX *a = new ZZ_pX[TEST_SIZE];
    ZZ_pX *b = new ZZ_pX[TEST_SIZE];

    for (size_t i = 0; i < TEST_SIZE; i++) {
        a[i] = random_ZZ_pX(127);
        b[i] = random_ZZ_pX(127);
    }

    ZZ_pX *results = new ZZ_pX[TEST_SIZE];

    auto start = chrono::high_resolution_clock::now();
    mul_test(results, a, b, TEST_SIZE);
    auto end = chrono::high_resolution_clock::now();

    // Total time costs, average time costs, and throughput
    double time_cost = chrono::duration<double, milli>(end - start).count();
    double avg_time_cost = time_cost / TEST_SIZE;
    double throughput = 1000 / avg_time_cost;

    cout << "Total time cost: " << time_cost << " ms" << endl;
    cout << "Average time cost: " << avg_time_cost << " ms" << endl;
    cout << "Throughput: " << throughput << " ops" << endl;


    return 0;
}
