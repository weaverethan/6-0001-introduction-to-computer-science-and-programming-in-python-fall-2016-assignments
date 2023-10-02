# Problem Set 4A
# Name: <your name here>
# Collaborators:
# Time Spent: x:xx

def get_permutations(sequence):
    '''
    Enumerate all permutations of a given string

    sequence (string): an arbitrary string to permute. Assume that it is a
    non-empty string.  

    You MUST use recursion for this part. Non-recursive solutions will not be
    accepted.

    Returns: a list of all permutations of sequence

    Example:
    >>> get_permutations('abc')
    ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']

    Note: depending on your implementation, you may return the permutations in
    a different order than what is listed here.
    '''
    if len(sequence) == 1:
        return [sequence]

    permutations = []
    
    for char_number in range(len(sequence)):
        
        selected_char =  sequence[char_number]

        remaining_sequence = sequence[:char_number] + sequence[char_number + 1:]

        permutations += [selected_char+remaining_sequence for remaining_sequence in get_permutations(remaining_sequence) ]

    return(permutations)
    

    pass #delete this line and replace with your code here

if __name__ == '__main__':
   
#    # Put three example test cases here (for your sanity, limit your inputs
#    to be three characters or fewer as you will have n! permutations for a 
#    sequence of length n)

    input = 'abcdefg'
    print('Input:', input)
    print('Expected Output:', ['abc', 'acb', 'bac', 'bca', 'cab', 'cba'])
    print('Actual Output:', get_permutations(input))

    pass #delete this line and replace with your code here

