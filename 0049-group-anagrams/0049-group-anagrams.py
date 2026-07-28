class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        #making a list to keep count of all the charecters
        #we make a hahsmap with these counters as key and keep the list of strings as values 
        hashmap = {}
        
        for i in strs:
            #counter list
            counter = [0]*(26)
            for j in i:
                counter[ord(j)-ord('a')] += 1
            
            #adding the counter list and the list into a hashmap
            counter = tuple(counter)
            if counter in hashmap:
                hashmap[counter].append(i)
            else:
                hashmap[counter] = [i]
            print(counter)
        print(hashmap)
        return list(hashmap.values())

