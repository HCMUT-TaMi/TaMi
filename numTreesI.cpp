 int numTrees(int n, int res = 0) {
        if (n == 0 || n == 1) return 1; 
        for(int i = 1; i <= n; i++) { 
            res += numTrees(n-i) * numTrees(i-1);
        }
        return res; 
    }
