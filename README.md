<h2> What is this project?</h2>
A program that performs Huffman Coding algorithm on a sample text file.

<h2> What is Huffman Coding? </h2>
It is a compression algorithm used to optimise the binary encoding of files by making the binary strings smaller in size, hence making the
whole file smaller in size but without losing any valuable information by doing so. Its core idea is assigning smaller bit strings to 
characters that repeat most often. So if I have a file that contains this sentence "The duck jumped into the truck buck bucket", the most 
repeated character here is "u" so instead of giving it the usual 8-bit string that the computer assigns automatically to char variables in C++,
we might give it a 4-bit string, for example. Hence shortening our total bit strings significantly. 

<h2> How are the bit strings assigned? </h2>
By building what's called a Huffman Tree. The bottom-most nodes of the tree are the letters and their frequencies inside
the text file. After construction, we traverse the tree from the top-most node. If we jump to a right-node, we concatenate '1' to our bit string;
if we jump to a left-node, we concatenate '0' to our bit string. Thereby forming our bit strings for each letter as we reach it. The most frequently repeated letters 
are at the top of the tree, while the least frequent are at the bottom. 

<h2> What does this program do? </h2>
1. reads text file
2. calculates frequency of each letter in the text file and stores it all in a freqArray
3. creates nodes grouping the frequencies and the characters and stores them in a priority queue
4. constructs huffman tree using the priority queue
5. outputs uncompressed codes of the characters in the file
6. calculates and outputs compressed version
7. compares between size of compressed file and size of uncompressed file

<h3> notes: </h3>
  -I have attached a drawing of the final composition of my tree as a .png file. You might find it is easier to follow the code with 
  a visual guide.
