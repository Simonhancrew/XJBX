class Solution:
    def removeDuplicates(self, S: str) -> str:
        st = []
        for ch in S:
            if st and ch == st[-1]:
                st.pop()
            else:
                st.append(ch)
        res = ""
        for ev in st:
            res += ev
        return res