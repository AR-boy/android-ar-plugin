public class main {
    static {
        System.loadLibrary("test_sorttt");
    }
    private native void TestSort(int[] myIntArray, int length);

    public void main(String[] args) {
        int[] myIntArray = new int[]{10, 5, 7};
        new main().TestSort(myIntArray, myIntArray.length);
    }
}
