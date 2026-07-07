class Solution:

    def encode(self, strs: List[str]) -> str:

        if len(strs) == 0: return "NULL"

        sep = "-"
        split = "|"
        encoded = []
        for word in strs:
            encoded_word = sep.join([str(ord(c)) for c in word])
            encoded.append(encoded_word)

        return split.join(encoded)

    def decode(self, s: str) -> List[str]:

        sep = "-"
        split = "|"
        decoded = []
        encoded = s.split(split) if s != "NULL" else []
        for word in encoded:
            encoded_word = word.split(sep)
            print(f'Encoded Word: {encoded_word}')
            decoded_word = "".join([
                str(chr(int(c))) 
                if c != "" else ""
                for c in encoded_word
            ])

            decoded.append(decoded_word)

        return decoded

