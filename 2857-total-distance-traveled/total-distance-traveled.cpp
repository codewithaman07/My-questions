class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return mainTank*10 + min((mainTank-1)/4, additionalTank)*10;
    }
};