# Extension Ring Benchmarks in NTL

This directory contains benchmarks for the extension ring arithmetic in NTL.

NTL version: 11.5.1

## Files

- `ExtensionRing.cpp`: Benchmark codes for base ring larger than 2^60.
- `ExtensionRingSmall.cpp`: Benchmark codes for base ring smaller or equal than 2^60.

## Compilation

`g++ -o big ExtensionRing.cpp -O3 -lntl`

`g++ -o small ExtensionRingSmall.cpp -O3 -lntl`

## Machine Setup

Cpuinfo Version: 9.0.0
Vendor ID Raw: GenuineIntel
Hardware Raw: 
Brand Raw: Intel(R) Xeon(R) Platinum
Hz Advertised Friendly: 2.5000 GHz
Hz Actual Friendly: 2.5000 GHz
Hz Advertised: (2500000000, 0)
Hz Actual: (2500000000, 0)
Arch: X86_64
Bits: 64
Count: 32
Arch String Raw: x86_64
L1 Data Cache Size: 524288
L1 Instruction Cache Size: 524288
L2 Cache Size: 16777216
L2 Cache Line Size: 256
L2 Cache Associativity: 6
L3 Cache Size: 34603008

## Results (10000 muls)

Module polynomial: `f = x^128 + x^7 + x^2 + x + 1`

### $Z_{2^{8}}$[X] / f[X]

```
Total time cost: 177.252 ms
Average time cost: 0.0177252 ms
Throughput: 56416.9 ops
```

### $Z_{2^{32}}$[X] / f[X]

```
Total time cost: 240.039 ms
Average time cost: 0.0240039 ms
Throughput: 41659.8 ops
```

### $Z_{2^{64}}$[X] / f[X]

```
Total time cost: 3165.91 ms
Average time cost: 0.316591 ms
Throughput: 3158.65 ops
```
