import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Quicksort {

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

  static int partition(int[] arr, int low, int high) {
    int pivot = arr[high];
    int currentIndex = low - 1;

    for (int i = low; i < high; i++) {
      if (arr[i] <= pivot) {
        currentIndex++;
        int tempSwap = arr[currentIndex];
        arr[currentIndex] = arr[i];
        arr[i] = tempSwap;
      }
    }
    int tempSwap = arr[currentIndex + 1];
    arr[currentIndex + 1] = arr[high];
    arr[high] = tempSwap;
    return currentIndex + 1;
  }

  static void quickSort(int[] originalArr, int low, int high) {
    if (low < high) {
      int partitionIndex = partition(originalArr, low, high);

      quickSort(originalArr, low, partitionIndex - 1);
      quickSort(originalArr, partitionIndex + 1, high);
    }
  }

  public static void main(String[] args) {
    try {
      int sortArray[] = readArrayFromFile(args[0]);
      int length = sortArray.length;

      final long startTime = System.currentTimeMillis();
      quickSort(sortArray, 0, sortArray.length - 1);
      final long endTime = System.currentTimeMillis();
      System.out.println(endTime - startTime);
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}
