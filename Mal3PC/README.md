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

### Summary of Experiments 2-7

| Experiment | Protocol           | Network | Time (seconds) | Communication (MB) |
|------------|--------------------|---------|----------------|--------------------|
| 2          | SpdzWise + Uss23   | LAN     | 233.023        | 289123             |
| 3          | Uss23 + CCS24      | LAN     | 243.792        | 46195.9            |
| 4          | SpdzWise + Uss23   | WAN     | 20282.4        | 289123             |
| 5          | Uss23 + CCS24      | WAN     | 5083.52        | 46195.9            |
| 6          | Passive            | WAN     | 4889.03        | 45483              |
| 7          | Passive            | LAN     | 50.0017        | 45483              |


### Summary of Experiments 2-7

These experiments are conducted on optimized programs with parameters `-O -l`.

| Experiment | Protocol           | Network | Time (seconds) | Communication (MB) |
|------------|--------------------|---------|----------------|--------------------|
| 8          | Passive            | LAN     | 33.243         | 45468.1            |
| 9          | SpdzWise + Uss23   | LAN     | 151.25         | 276645             |
| 10         | Uss23 + CCS24      | LAN     | 202.5          | 46180.1            |

### Experiment 1

Uss23 + CCS24, single thread, LAN, single machine.

**Args:**

`tf-EzPC_Athos_Networks_ResNet_graphDef.bin-1-trunc_pr -b 100000 -ms 100 -bb 100000 -tn 32`

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

### Experiment 2

SpdzWise + Uss23, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./sw-uss23-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

LAN on three machines.

**Results:**

```
The following benchmarks are including preprocessing (offline phase).
Time = 233.023 seconds 
Time1 = 223.529 seconds (95928 MB, 13783016 rounds)
Data sent = 96598.6 MB in ~13790655 rounds (party 0 only; rounds counted double due to multi-threading; use '-v' for more details)
Global data sent = 289123 MB (all parties)
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
        program.use_split(3)
```

### Experiment 3

Uss23 + CCS24, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./mal3pc-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

LAN on three machines.

**Results:**

```
The following benchmarks are including preprocessing (offline phase).
Time = 243.792 seconds 
Time1 = 197.782 seconds (15292.3 MB, 3344094 rounds)
Data sent = 15535.9 MB in ~3347285 rounds (party 0 only; rounds counted double due to multi-threading; use '-v' for more details)
Global data sent = 46195.9 MB (all parties)
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
        program.use_trunc_pr = True
        program.use_split(3)
```

### Experiment 4

SpdzWise + Uss23, 32 threads, WAN, three machines.

**Command:**

`taskset -c 0-31 ./sw-uss23-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

WAN on three machines.

Bandwidth: 300Mbit/s, latency: 80ms.

**Results:**

```
33 threads spent a total of 551778 seconds (21850 MB, 13568388 rounds) on the online phase, 51806 seconds (74748.3 MB, 221508 rounds) on the preprocessing/offline phase, and 65191.4 seconds idling.
Communication details (rounds in parallel threads counted double):
Broadcasting 95.2031 MB in 3491466 rounds, taking 146504 seconds
Passing around 90543 MB in 10004947 rounds, taking 445189 seconds
Receiving directly 5526.66 MB in 145867 rounds, taking 9959.17 seconds
Sending directly 5865.25 MB in 148375 rounds, taking 82.6659 seconds
CPU time = 4122.5 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 20282.4 seconds 
Time1 = 19965.2 seconds (95928 MB, 13783016 rounds)
Data sent = 96598.6 MB in ~13790655 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 289123 MB (all parties)
Actual cost of program:
  Type int
    1225058572           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_split(3)
Command line: ./sw-uss23-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```

### Experiment 5

Uss23 + CCS24, 32 threads, WAN, three machines.

**Command:**

`taskset -c 0-31 ./mal3pc-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

WAN on three machines.

Bandwidth: 300Mbit/s, latency: 80ms.

**Results:**

```
33 threads spent a total of 142628 seconds (5652.42 MB, 3338421 rounds) on the online phase, 7628.45 seconds (9845.85 MB, 8204 rounds) on the preprocessing/offline phase, and 15769.7 seconds idling.
Communication details (rounds in parallel threads counted double):
Passing around 5484.12 MB in 3336552 rounds, taking 138721 seconds
Receiving directly 9845.85 MB in 4102 rounds, taking 4841.38 seconds
Sending directly 10051.8 MB in 6631 rounds, taking 2597.29 seconds
CPU time = 5201.33 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 5083.52 seconds 
Time1 = 4978.66 seconds (15292.3 MB, 3344094 rounds)
Data sent = 15535.9 MB in ~3347285 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 46195.9 MB (all parties)
Actual cost of program:
  Type int
    1225058572           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_trunc_pr = True
	program.use_split(3)
Command line: ./mal3pc-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose

```

### Experiment 6

Passive, 32 threads, WAN, three machines.

**Command:**

`taskset -c 0-31 ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose`

WAN on three machines.

Bandwidth: 300Mbit/s, latency: 80ms.

**Results:**

```
33 threads spent a total of 139184 seconds (5452.48 MB, 3335861 rounds) on the online phase, 7614.97 seconds (9845.85 MB, 8204 rounds) on the preprocessing/offline phase, and 14532.7 seconds idling.
Communication details (rounds in parallel threads counted double):
Passing around 5246.5 MB in 3333332 rounds, taking 138828 seconds
Receiving directly 9845.85 MB in 4102 rounds, taking 5086.38 seconds
Sending directly 10051.8 MB in 6631 rounds, taking 2405.74 seconds
CPU time = 850.865 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 4889.03 seconds 
Time1 = 4882.35 seconds (15092.4 MB, 3341534 rounds)
Data sent = 15298.3 MB in ~3344065 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 45483 MB (all parties)
Actual cost of program:
  Type int
    1225058572           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_trunc_pr = True
	program.use_split(3)
Command line: ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```

### Experiment 7

Passive, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose`

LAN on three machines.

**Results:**

```
33 threads spent a total of 1131.08 seconds (5452.48 MB, 3335861 rounds) on the online phase, 262.558 seconds (9845.85 MB, 8204 rounds) on the preprocessing/offline phase, and 250.33 seconds idling.
Communication details (rounds in parallel threads counted double):
Passing around 5246.5 MB in 3333332 rounds, taking 754.836 seconds
Receiving directly 9845.85 MB in 4102 rounds, taking 62.7672 seconds
Sending directly 10051.8 MB in 6631 rounds, taking 21.2078 seconds
CPU time = 952.398 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 50.0017 seconds 
Time1 = 47.3892 seconds (15092.4 MB, 3341534 rounds)
Data sent = 15298.3 MB in ~3344065 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 45483 MB (all parties)
Actual cost of program:
  Type int
    1225058572           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_trunc_pr = True
	program.use_split(3)
Command line: ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```

### Experiment 8

**From Exp. 8, the program we ran are compiled by parameter `-O -l`** 

Passive, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose`

LAN on three machines.

**Results:**

```
Using statistical security parameter 40
Trying to run 64-bit computation
Starting timer 1 at 0 (0 MB, 0 rounds) after 4.3237e-05
Stopped timer 1 at 30.5246 (15087.4 MB, 371518 rounds)
guess 249
Compiler: ./compile.py tf EzPC/Athos/Networks/ResNet/graphDef.bin 32 -O -l -R 64
Main thread communication:
Passing around 0.484032 MB in 84 rounds, taking 0.0200535 seconds
Receiving directly 2.40026 MB in 1 rounds, taking 0.0108977 seconds
Sending directly 208.379 MB in 265 rounds, taking 0.236749 seconds

33 threads spent a total of 547.202 seconds (5447.49 MB, 363580 rounds) on the online phase, 295.434 seconds (9845.85 MB, 8204 rounds) on the preprocessing/offline phase, and 245.075 seconds idling.
Communication details (rounds in parallel threads counted double):
Passing around 5241.51 MB in 363316 rounds, taking 157.448 seconds
Receiving directly 9845.85 MB in 4102 rounds, taking 76.5326 seconds
Sending directly 10051.8 MB in 4366 rounds, taking 24.6481 seconds
CPU time = 651.74 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 33.243 seconds 
Time1 = 30.5246 seconds (15087.4 MB, 371518 rounds)
Data sent = 15293.3 MB in ~371784 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 45468.1 MB (all parties)
Actual cost of program:
  Type int
    1224714508           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_trunc_pr = True
	program.use_split(3)
Command line: ./replicated-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```

### Experiment 9

SpdzWise + Uss23, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./sw-uss23-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

LAN on three machines.

**Results:**

```
33 threads spent a total of 1649.48 seconds (17690.8 MB, 1546738 rounds) on the online phase, 2180.72 seconds (74748.3 MB, 221508 rounds) on the preprocessing/offline phase, and 1116.41 seconds idling.
Communication details (rounds in parallel threads counted double):
Broadcasting 12.7332 MB in 467402 rounds, taking 162.356 seconds
Passing around 86718.4 MB in 1260506 rounds, taking 997.561 seconds
Receiving directly 5357.07 MB in 20427 rounds, taking 51.5044 seconds
Sending directly 5695.66 MB in 20670 rounds, taking 17.9367 seconds
CPU time = 2848.44 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 151.25 seconds 
Time1 = 141.069 seconds (91768.8 MB, 1765896 rounds)
Data sent = 92439.5 MB in ~1769005 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 276645 MB (all parties)
Actual cost of program:
  Type int
    1224714508           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_split(3)
Command line: ./sw-uss23-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```

### Experiment 10

Uss23 + CCS24, 32 threads, LAN, three machines.

**Command:**

`taskset -c 0-31 ./mal3pc-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config`

LAN on three machines.

**Results:**

```
33 threads spent a total of 4333.66 seconds (5647.43 MB, 366140 rounds) on the online phase, 413.642 seconds (9845.85 MB, 8204 rounds) on the preprocessing/offline phase, and 1191.18 seconds idling.
Communication details (rounds in parallel threads counted double):
Passing around 5478.87 MB in 366536 rounds, taking 222.123 seconds
Receiving directly 9845.85 MB in 4102 rounds, taking 106.192 seconds
Sending directly 10051.8 MB in 4366 rounds, taking 21.8714 seconds
CPU time = 5094.18 (overall core time)
The following benchmarks are including preprocessing (offline phase).
Time = 202.5 seconds 
Time1 = 157.242 seconds (15287.3 MB, 374078 rounds)
Data sent = 15530.7 MB in ~375004 rounds (party 0 only; rounds counted double due to multi-threading)
Global data sent = 46180.1 MB (all parties)
Actual cost of program:
  Type int
    1224714508           Bits
This program might benefit from some protocol options.
Consider adding the following at the beginning of your code:
	program.use_trunc_pr = True
	program.use_split(3)
Command line: ./mal3pc-ring-party.x 0 tf-EzPC_Athos_Networks_ResNet_graphDef.bin-32 -B 4 -b 300000 -bb 640000 -ms 100 -tn 32 -ip mpspdz-config --verbose
```