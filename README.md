This is a test which was given to me at a job interview recently.

The idea was (as I remember it, some details could be wrong) to open a text file and answer the following questions :
- What is the most frequently used word ?
- What is the 25th most frequently used word ?
- What is the number of occurences of a specific word (which I don't remember, so I took "species" as an example) ?

Caveat : a word is defined by the regular expression [a-zA-z0-9\\.], preceded and followed by a whitespace.

A shell one-liner can surely answer these questions, for instance this (adding tail or grep at the end to answer the specific questions) :  
```
cat darwin.txt | sed -e 's/ /  /g' -e 's/\( [0-9a-zA-Z\.]\+ \)/\n\1\n/g' | grep ' [0-9a-zA-Z\.]\+ ' | sort | uniq -c | sort -n
```

However since this interview was for a C++ job, this repo contains a C++ implementation.

Usage :  
`make && ./a.out darwin.txt`
