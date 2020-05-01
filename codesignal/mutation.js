/*
hard

codewriting

4000

A gene can be represented by a string that is 8 characters long and contains only the characters 'A', 'C', 'G', and 'T'. You want to investigate the number of mutations that it takes to get from startStr to endStr, where one mutation is defined as a change to one single character in the gene string. You also have a bank that contains a listing of all valid gene mutations. A gene must be in the bank in order to be considered a valid gene string mutation.

Determine the minimum number of valid mutations needed to obtain endStr from startStr. startStr is assumed to be valid, so it might not be included in the bank. If multiple mutations are needed, all mutations in the sequence must be valid. You may also assume that startStr and endStr are distinct. If there is no such mutation, return -1.

Example

    For startStr = "AACCGGTT", endStr = "AACCGGTA",
    and bank = ["AACCGGTA"], the output should be
    minimumGeneticMutation(startStr, endStr, bank) = 1.

    "AACCGGTT" -> "AACCGGTA" represents 1 mutation.

    For startStr = "AACCGGTT", endStr = "AAACGGTA",
    and bank = ["AACCGGTA", "AACCGCTA", "AAACGGTA"], the output should be
    minimumGeneticMutation(startStr, endStr, bank) = 2.

    It takes 2 mutations to get from startStr to endStr: "AACCGGTT" -> "AACCGGTA", then "AACCGGTA" -> "AAACGGTA".

    For startStr = "AAAAACCC", endStr = "AACCCCCC",
    and bank = ["AAAACCCC", "AAACCCCC", "AACCCCCC"], the output should be
    minimumGeneticMutation(startStr, endStr, bank) = 3.

    It takes 2 mutations to get from startStr to endStr: "AAAAACCC" -> "AAAACCCC", then "AAAACCCC" -> "AAACCCCC", then "AAACCCCC" -> "AACCCCCC".

Input/Output

    [execution time limit] 4 seconds (js)

    [input] string startStr

    Guaranteed constraints:
    startStr.length = 8,
    startStr[i] ∈ {'A', 'C', 'G', 'T'}.

    [input] string endStr

    Guaranteed constraints:
    endStr.length = 8,
    endStr[i] ∈ {'A', 'C', 'G', 'T'}.

    [input] array.string bank

    An array containing strings that represent valid mutations.

    Guaranteed constraints:
    0 ≤ bank.length ≤ 100,
    bank[i].length = 8,
    bank[i][j] ∈ {'A', 'C', 'G', 'T'}.

    [output] integer
        An integer representing the number of valid mutations needed to get from startStr to endStr.
*/

// Todo
// 1 - what's the most appropriate CTRL-Z for a given endStr ?
//
//

function diff ( a, b) {
	let c = 0;
	for (let i = 0; i < a.length; i++) {
		if ( a[a.length - i - 1] != b[a.length - i - 1] )
			c++;
	}
	return c;
}
function goBack( track, startStr, endStr, bank) {
	let min_diff = Infinity;
	let ctrlz_dna = null;
	let new_bank = [];
	let to_rem_idx = -1;
	bank.forEach( (dna, i) => {
		let cur_diff = diff(dna, startStr);
		if ( cur_diff == 1 && dna != endStr ) {
			min_diff = cur_diff;
			ctrlz_dna = dna ;
			to_rem_idx = i;
		}
	});
	
	track.count++;
	track.dna = ctrlz_dna;
	console.log(new_bank, track)
	
	if ( min_diff < 0 ) {
		track.count = -1;
		return;
	}
	
	if ( startStr != track.dna ) {
		goBack(track, startStr, ctrlz_dna, bank );
	}
}

function minimumGeneticMutation(startStr, endStr, bank) {
	// simple stuff... let's ctrl+zzzzzZZ
	// endStr must be in the bank
	if ( ! bank.includes( endStr ) )
		return -1;
	
	let track = { count : 0, dna : ''};
	goBack( track, startStr, endStr, bank) ;
	return track.dna != startStr ? -1 : track.count - 1;
}
/*
    For startStr = "AAAAACCC", endStr = "AACCCCCC",
    and bank = ["AAAACCCC", "AAACCCCC", "AACCCCCC"], the output should be
    minimumGeneticMutation(startStr, endStr, bank) = 3.
*/
console.log( minimumGeneticMutation('AAAAACCC', 'AACCCCCC', ["AAAACCCC", "AAACCCCC", "AACCCCCC"]) )