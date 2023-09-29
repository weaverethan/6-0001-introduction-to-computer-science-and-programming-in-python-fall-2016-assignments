# Problem Set 4C
# Name: <your name here>
# Collaborators:
# Time Spent: x:xx

import string
import random
import re
from ps4a import get_permutations

### HELPER CODE ###
def load_words(file_name):
    '''
    file_name (string): the name of the file containing 
    the list of words to load    
    
    Returns: a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    '''
    
    print("Loading word list from file...")
    # inFile: file
    inFile = open(file_name, 'r')
    # wordlist: list of strings
    wordlist = []
    for line in inFile:
        wordlist.extend([word.lower() for word in line.split(' ')])
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def is_word(word_list, word):
    '''
    Determines if word is a valid word, ignoring
    capitalization and punctuation

    word_list (list): list of words in the dictionary.
    word (string): a possible word.
    
    Returns: True if word is in word_list, False otherwise

    Example:
    >>> is_word(word_list, 'bat') returns
    True
    >>> is_word(word_list, 'asdf') returns
    False
    '''
    word = word.lower()
    word = word.strip(" !@#$%^&*()-_+={}[]|\:;'<>?,./\"")
    return word in word_list


### END HELPER CODE ###

WORDLIST_FILENAME = 'words.txt'

# you may find these constants helpful
VOWELS_LOWER = 'aeiou'
VOWELS_UPPER = 'AEIOU'
CONSONANTS_LOWER = 'bcdfghjklmnpqrstvwxyz'
CONSONANTS_UPPER = 'BCDFGHJKLMNPQRSTVWXYZ'

class SubMessage(object):
    def __init__(self, text):
        '''
        Initializes a SubMessage object
                
        text (string): the message's text

        A SubMessage object has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
        '''
        self.message_text = text
        self.valid_words = load_words("words.txt")
    
    def get_message_text(self):
        '''
        Used to safely access self.message_text outside of the class
        
        Returns: self.message_text
        '''
        return self.message_text

    def get_valid_words(self):
        '''
        Used to safely access a copy of self.valid_words outside of the class.
        This helps you avoid accidentally mutating class attributes.
        
        Returns: a COPY of self.valid_words
        '''
        return self.valid_words.copy()
                
    def build_transpose_dict(self, vowels_permutation):
        '''
        vowels_permutation (string): a string containing a permutation of vowels (a, e, i, o, u)
        
        Creates a dictionary that can be used to apply a cipher to a letter.
        The dictionary maps every uppercase and lowercase letter to an
        uppercase and lowercase letter, respectively. Vowels are shuffled 
        according to vowels_permutation. The first letter in vowels_permutation 
        corresponds to a, the second to e, and so on in the order a, e, i, o, u.
        The consonants remain the same. The dictionary should have 52 
        keys of all the uppercase letters and all the lowercase letters.

        Example: When input "eaiuo":
        Mapping is a->e, e->a, i->i, o->u, u->o
        and "Hello World!" maps to "Hallu Wurld!"

        Returns: a dictionary mapping a letter (string) to 
                 another letter (string). 
        '''
        
        #self.lower_dic = {letter: '' for letter in string.ascii_lowercase}
        #self.upper_dic = {letter: '' for letter in string.ascii_uppercase}
        #temp_lower = [letter for letter in string.ascii_lowercase]
        #temp_upper = [letter for letter in string.ascii_uppercase]
        #

        #for letter in self.lower_dic.keys():
        #    random_char = random.choice(temp_lower)
        #    self.lower_dic[letter] = random_char
        #    temp_lower.remove(random_char)
        #
        #for letter in self.upper_dic.keys():
        #    random_char = random.choice(temp_upper)
        #    self.upper_dic[letter] = random_char
        #    temp_upper.remove(random_char)

        #scramble_dic = {**self.upper_dic, **self.lower_dic}

        vowels_permutation = vowels_permutation.lower()+vowels_permutation.upper()
        scramble_dic = {}    
        for vowel, permutation in zip('aeiouAEIOU',vowels_permutation):
            scramble_dic[vowel] = permutation


        return scramble_dic

        
    
    def apply_transpose(self, transpose_dict):
        '''
        transpose_dict (dict): a transpose dictionary
        
        Returns: an encrypted version of the message text, based 
        on the dictionary
        '''
        list_message = list(self.message_text)

        
        for index, letter in enumerate(list_message):
            if letter in transpose_dict.keys():
                list_message[index] = transpose_dict[letter]

        self.encrypted_message = ''.join(list_message)

        return self.encrypted_message
        
class EncryptedSubMessage(SubMessage):
    def __init__(self, text):
        '''
        Initializes an EncryptedSubMessage object

        text (string): the encrypted message text

        An EncryptedSubMessage object inherits from SubMessage and has two attributes:
            self.message_text (string, determined by input text)
            self.valid_words (list, determined using helper function load_words)
        '''
        super().__init__(text)
        

    def decrypt_message(self):
        '''
        Attempt to decrypt the encrypted message 
        
        Idea is to go through each permutation of the vowels and test it
        on the encrypted message. For each permutation, check how many
        words in the decrypted text are valid English words, and return
        the decrypted message with the most English words.
        
        If no good permutations are found (i.e. no permutations result in 
        at least 1 valid word), return the original string. If there are
        multiple permutations that yield the maximum number of words, return any
        one of them.

        Returns: the best decrypted message    
        
        Hint: use your function from Part 4A
        '''


        standard_vowels = "aeiouh"
        list_of_keys = []
    
        for permutation in get_permutations(standard_vowels):
            dic = {}
            for basic_vowel, permutation_vowel in zip(standard_vowels,permutation):
                dic[basic_vowel] = permutation_vowel
            list_of_keys.append(dic)

        words_in_attempt = {}

        for dic_number, dictionary in enumerate(list_of_keys):
            message_list = [letter.lower() for letter in self.message_text]
            for index, letter in enumerate(message_list):
                if letter in dictionary:
                    message_list[index] = dictionary[letter]
            message = ((re.sub(r'[^\w\s]', '', (''.join(message_list))))).split()
            for word in message:
                if word in self.valid_words:
                    words_in_attempt[dic_number] = words_in_attempt.get(dic_number, 0) + 1
                    
        
        
        
        return (list_of_keys[max(words_in_attempt, key=words_in_attempt.get)])
            

if __name__ == '__main__':

    # Example test case
    #message = SubMessage("Hello World!")
    #permutation = "eaiuo"
    #enc_dict = message.build_transpose_dict(permutation)
    #print("Original message:", message.get_message_text(), "Permutation:", permutation)
    #print("Expected encryption:", "Hallu Wurld!")
    #print("Actual encryption:", message.apply_transpose(enc_dict))
    #enc_message = EncryptedSubMessage(message.apply_transpose(enc_dict))
    #print("Decrypted message:", enc_message.decrypt_message())
    message = EncryptedSubMessage("HAlle Werld whit us yeor nima?")
    test = SubMessage('HEllo World what is your name?')
    print(test.apply_transpose(test.build_transpose_dict("iaueo")))
    print(message.decrypt_message())
     
    #TODO: WRITE YOUR TEST CASES HERE
