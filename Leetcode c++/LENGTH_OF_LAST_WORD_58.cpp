class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        bool foundnonspace=false;
        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i]==' ' && !foundnonspace)
            {
                continue;
            }
            else if(s[i]==' ' && foundnonspace )
            {
                break;
            }
            else
            {
                count++;
                foundnonspace=true;
            }

        
        }
        return count;
    }
};

/*
1->Initialize count variable and nonspace as false
2->iterate backwards
3->if s[i] == ' ' and the character is not found that !foundnonspace then continue
4-> else if s[i]==' ' and the character is found that is foundnonspace the break
5-> else count++ and set nonspace as true
5->return count

Time complexity--> O(N)


Solution-2 (more efficient than above)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        
        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            else
            {
                if(count>0)
                {
                break;
            	}
            
            }
        }
        return count;
    }
};
*/
