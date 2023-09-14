#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
public:
    class Node
    {
        private:
        int numRows;
        bool full;
        vector<char> line_v;
        vector<char> line_h;
        string toString(char c)
        {
            if(c==' ') return "";
            string res;
            res.push_back(c);
            return res;
        }

        public:
        Node(int n)
        {
            numRows=n;
            full=false;
        }
        void push_back(char c)
        {
            if(full) return;
            if(line_v.size()<numRows)
            {
                line_v.push_back(c);
                if(numRows==2&&line_v.size()==2)
                    full=true;
                return;
            } 
            if(line_v.size()>=numRows)
            {
                line_h.push_back(c);
                if(line_h.size()>=numRows-2) full=true;
            }
        }
        string get_line(int n)
        {
            if(n==0) return toString(line_v[0]);
            else if(n==numRows-1) return toString(line_v[n]);
            else return toString(line_v[n])+toString(line_h[numRows-n-2]);
        }
        bool isFull(){return full;}
    };
    
    string convert(string s,int numRows) 
    {
        if(numRows==1) return s;
        vector<Node> nodes;
        Node empty_node(numRows);
        nodes.push_back(empty_node);
        for(int i=0;i<s.size();i++)
        {
            if(nodes[nodes.size()-1].isFull())
                nodes.push_back(empty_node);
            nodes[nodes.size()-1].push_back(s[i]);
        }
        while(!nodes[nodes.size()-1].isFull())
        {
            nodes[nodes.size()-1].push_back(' ');
        }
        string* lines=new string [numRows];
        string result;
        for(auto node:nodes)
        {
            for(int i=0;i<numRows;i++)
                lines[i]+=node.get_line(i);
        }
        for(int i=0;i<numRows;i++)
        {
            result+=lines[i];
        }
        delete[] lines;
        return result;
    }
};