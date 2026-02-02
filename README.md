i like solving rubiks cubes blindfolded, which means i need to practice my algorithms! this allows the generation of any amount of random letter pairs you want. in the main function, simply change the value of the variable to generate more or less pairs. the default values are the average amount of pairs in a solve. 
This is made with speffz in mind, but you can change the vector pieces to match your scheme. a set of curly brackets is one piece. for example, on corners, {A, E, R} corresponds to the UBL piece, so you can replace these with your letters instead. for centers, the same logic applies but for faces instead of pieces. finally, wings don't have this restriction, so enter every letter except your buffer and it will work.
Notes:
- Every pair generated in a solve is unique
- Inverses of pairs can appear, for example BQ and QB
- pairs like AA or BB will not appear


I believe this covers everything. hope you find this useful. i know many tools like this exist, but i was bored so i decided to make my own.
