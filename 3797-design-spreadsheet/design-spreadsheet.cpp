class Spreadsheet {
public:
    vector<vector<int>>nums;
    Spreadsheet(int rs) {
        nums.assign(rs, vector<int>(26,0));
    }
    
    void setCell(string cell, int val) {
        int r = stoi(cell.substr(1))-1;
        int c = cell[0]-'A';
        nums[r][c] = val;
    }
    
    void resetCell(string cell) {
        int r = stoi(cell.substr(1))-1;
        int c = cell[0]-'A';
        nums[r][c] = 0;
    }
    int getValue(string formula) {
        string expr = formula.substr(1);
        auto pos = expr.find('+');
        string first = expr.substr(0, pos);
        string second = expr.substr(pos + 1);
        int val1 = 0, val2 = 0;
        if(first[0] >= 'A' && first[0] <= 'Z'){
            int c = first[0] - 'A';
            int r = stoi(first.substr(1))-1;
            val1 = nums[r][c];
        } 
        else val1 = stoi(first);
        if(second[0] >= 'A' && second[0] <= 'Z'){
            int c = second[0] - 'A';
            int r = stoi(second.substr(1))-1;
            val2 = nums[r][c];
        } 
        else val2 = stoi(second);
        return val1 + val2;
    }

};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rs);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */