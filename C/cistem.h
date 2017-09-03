/*	CISTEM Stemmer for German

	This is the official Perl implementation of the CISTEM stemmer.
	It is based on the paper
	Leonie Weißweiler, Alexander Fraser (2017). Developing a Stemmer for German Based on a Comparative Analysis of Publicly Available Stemmers. In Proceedings of the German Society for Computational Linguistics and Language Technology (GSCL)
	which can be read here:
	http://www.cis.lmu.de/~weissweiler/cistem/
	
	In the paper, we conducted an analysis of publicly available stemmers, developed
	two gold standards for German stemming and evaluated the stemmers based on the
	two gold standards. We then proposed the stemmer implemented here and show
	that it achieves slightly better f-measure than the other stemmers and is
	thrice as fast as the Snowball stemmer for German while being about as fast as
	most other stemmers.
*/

#ifndef CISTEM_H
#define CISTEM_H

/*	This method takes the word to be stemmed and a boolean specifiying if case-insensitive stemming should be used and returns the stemmed word. If only the word
	is passed to the method or the second parameter is 0, normal case-sensitive stemming is used, if the second parameter is 1, case-insensitive stemming is used.
	
	Case sensitivity improves performance only if words in the text may be incorrectly upper case.
	For all-lowercase and correctly cased text, best performance is achieved by
	using the case-sensitive version.
*/
wchar_t* stem(wchar_t* word);
wchar_t* stem_case_insensitive(wchar_t* word);

/*	This method works very similarly to stem. The only difference is that in
	addition to returning the stem, it also returns the rest that was removed at
	the end. To be able to return the stem unchanged so the stem and the rest
	can be concatenated to form the original word, all subsitutions that altered
	the stem in any other way than by removing letters at the end were left out.
	
	The return value is an array that contains a pointer to the stem first, then
	to the suffix second
*/
wchar_t** segment(wchar_t* word);
wchar_t** segment_case_insensitive(wchar_t* word);

#endif