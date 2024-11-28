# Mal3PC Protocol

Mal3PC includes two protocols: [Malicious 3PC Binary](https://eprint.iacr.org/2023/909) and [Malicious 3PC Arithmetic](https://eprint.iacr.org/2024/700). This mixed protocol is implemented under [MP-SPDZ](https://github.com/data61/MP-SPDZ) framework and the codes are available at [Mal3PC](https://github.com/DuanYuFi/malicious-3pc).

## Machine Setup

```
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
```

with memory 256GB.

## Experiments

### Experiment 1

**Args:**

`-b 100000 -ms 100 -bb 100000 -tn 32`

LAN on a single machine.


**Results:**

```
The following benchmarks are including preprocessing (offline phase).
Time = 772.975 seconds 
Time1 = 770.006 seconds (8587.29 MB, 3414563 rounds)
Data sent = 8793.61 MB in ~3417130 rounds (party 0 only; rounds counted double due to multi-threading; use '-v' for more details)
Global data sent = 26773.8 MB (all parties)
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
        program.use_split(3)
```