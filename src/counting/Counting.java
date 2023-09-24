import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Counting {

  static int[] readArrayFromFile(String fileName) throws IOException {
    BufferedReader buffer = new BufferedReader(new FileReader(fileName));
    try {
      int arrToReturn[] = {};
      String line;

      while ((line = buffer.readLine()) != null) {
        arrToReturn = Arrays.copyOf(arrToReturn, arrToReturn.length + 1);
        arrToReturn[arrToReturn.length - 1] = Integer.parseInt(line);
      }
      return arrToReturn;
    } finally {
      buffer.close();
    }
  }

  static int arrayMax(int arr[]) {
    int max = 0;
    for (int item : arr) {
      if (item > max) {
        max = item;
      }
    }
    return max;
  }

  static int[] countOccurences(int[] arr, int max) {
    int[] occurences = new int[max + 1];
    Arrays.fill(occurences, 0);
    for (int item : arr) {
      occurences[item]++;
    }
    return occurences;
  }

  static int[] countingSort(int[] originalArr) {
    int[] outputArr = Arrays.copyOf(originalArr, originalArr.length);
    int max = arrayMax(originalArr);
    int[] occurences = countOccurences(originalArr, max);
    // Sum up predecessors
    for (int i = 1; i < occurences.length; i++) {
      occurences[i] += occurences[i - 1];
    }

    // Shift array to the right
    for (int i = occurences.length - 1; i > 0; i--) {
      occurences[i] = occurences[i - 1];
    }
    occurences[0] = 0;
    // Sort Array
    for (int i = 0; i < originalArr.length; i++) {
      int currentValue = originalArr[i];
      outputArr[occurences[currentValue]] = currentValue;
      occurences[currentValue]++;
    }
    return outputArr;
  }

  public static void main(String[] args) {
    try {
      int sortArray[] = readArrayFromFile(args[0]);
      int length = sortArray.length;

      final long startTime = System.currentTimeMillis();
      int sortedArray[] = countingSort(sortArray);
      final long endTime = System.currentTimeMillis();

      System.out.println(endTime - startTime);
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
