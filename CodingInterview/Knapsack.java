import java.util.*;

class Knapsack{

    int WEIGHT_LIMIT = 130;
    int maxVal;
    HashSet<Integer> bestSolution;

    public static void main(String[] args){
        Knapsack k = new Knapsack();
        int[] weights = {20, 8, 60, 55, 40, 70, 85, 25, 
                        30, 65, 75, 10, 95, 50, 40, 10};
        int[] values =  {65, 35, 245, 195, 65, 150, 275, 155,
                        120, 320, 75, 40, 200, 100, 220, 99};
        HashSet<Integer> indicesToTake = k.solveKnapsack(weights, values);
        System.out.println(indicesToTake);
    }

    public HashSet<Integer> solveKnapsack(int[] w, int[] v){
        maxVal = 0;
        bestSolution = null;
        solveKnapsackHelper(new HashSet<Integer>(), w, v, 0, 0);
        return bestSolution;
    }

    private void solveKnapsackHelper(HashSet<Integer> used, 
            int[] weights, int[] values, 
            int weightSoFar, int valSoFar){
        if(weightSoFar > WEIGHT_LIMIT){
            return;
        }
        if(valSoFar > maxVal){
            maxVal = valSoFar;
            bestSolution = used;
        }
        for(int i = 0; i < weights.length; i++){
            if(!used.contains(i)){
                HashSet<Integer> newUsed = new HashSet<Integer>(used);
                newUsed.add(i);
                solveKnapsackHelper(newUsed, weights, values, 
                    weightSoFar + weights[i], valSoFar + values[i]);
            }
        } 
    }

}
