i like solving rubiks cubes blindfolded, which means i need to practice my algorithms! this allows the generation of any amount of random letter pairs you want. in the main function, simply change the value of the variables to generate more or less pairs. the default values are the average amount of pairs in a solve. 
This is made with speffz in mind, but you can change the vector pieces to match your scheme. a set of curly brackets is one piece. for example, on corners, {A, E, R} corresponds to the UBL piece, so you can replace these with your letters instead. for centers, the same logic applies but for faces instead of pieces. finally, wings don't have this restriction, so enter every letter except your buffer and it will work. Obviously the edges function works for midges too, and the centers function covers both + and x.

Notes:
- Every pair generated is unique
- Inverses of pairs can appear, for example BQ and QB
- pairs like AA or BB will not appear

To install this program, you can run the following command:
```bash
git clone https://github.com/bilalElr/rubiks-cube-blindfolded-letter-pair-generator.git && cd rubiks-cube-blindfolded-letter-pair-generator && chmod +x build.sh && ./build.sh
```

How to use:
```
./comms [piece type] [count]
-c    		generate corner pairs
-e 		generate edge pairs
-w 		generate wing pairs
-x  		generate center pairs
```

Example output for edge pairs:
```
./comms -e 6
======== Generated edge pairs ========
MP
PW
MW
XP
LU
WM
============ END ============
```

Example output for center pairs:
```
./comms -x 10
======== Generated center pairs ========
KF
FR
PF
QP
BU
TN
UF
EQ
RC
PB
============ END ============
```


I believe this covers everything. hope you find this useful. i know many tools like this exist, but i was bored so i decided to make my own.
