# CS 104 Project Repository

- **Name**: Taegyum Kim
- **USC ID**: 3726241603
- **Email**: taegyumk@usc.edu

To compile the program, qmake -project, then qmake, then make.
There should be executable called project_taegyumk.
In order to run it, type ./project_taegyumk data/data.txt.
 
data.txt is the text file that has userdata text file in the first line and moviedata text file in the second line.
data.txt is in the data folder.
userdata text file and moviedata text file are in the data folder too.
Therefore, in data.txt, data/userdata.txt and data/moviedata.txt are stored.

I stored all the QT classes and netflix, main.cpp in the main directory and map, set, queue is in lib folder.

-------------------------------------

For step 5, I did

1) change to STL
6) add actors in userdata text file, search by actors for Movie
11) Modify rating

I created setintersection function in my netflix since I changed my SET to STL set.
I used setintersection to calculate similarity and the functions returns vector that has similarities.
to find basic similarity, I add all similarities in vector and divided by size of vector. 


The movie data file format for searching by actors is
Actor that I have A,B,C,D,E . 

BEGIN the princess bride
KEYWORD: comedy
KEYWORD: Inigo Montoya
KEYWORD: Robin Wright
ACTOR: Taegyum
ACTOR: KIM
ACTOR: HI
END

it has part2 folder and it is for part2 regrading.




