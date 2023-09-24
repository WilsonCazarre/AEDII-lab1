import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Bubble {

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

  static void bubbleSort(int[] arr) {
    for (int i = arr.length; i > 0; i--) {
      for (int j = 1; j < i; j++) {
        if (arr[j - 1] > arr[j]) {
          int aux = arr[j - 1];
          arr[j - 1] = arr[j];
          arr[j] = aux;
        }
      }
    }
  }

  public static void main(String[] args) throws Exception {
    try {
      int sortArray[] = readArrayFromFile(args[0]);
      final long startTime = System.currentTimeMillis();
      bubbleSort(sortArray);
      final long endTime = System.currentTimeMillis();
      System.out.println(endTime - startTime);
    } catch (Exception e) {
      throw e;
    }
  }
}
