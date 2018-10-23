import org.junit.Test;
import static org.junit.Assert.*;

public class VectorTest {
    static final double DELTA = 0.0001;
    @Test
    public void testVector() {
        double[] arr = new double[]{1.5, 3.5};
        Vector v = new Vector(arr);
        assertEquals(2, v.getDimension());
        assertEquals(1.5, v.getComponent(1), DELTA);
        assertEquals(3.5, v.getComponent(2), DELTA);
    }

    @Test
    public void testVectorLength() {
        double[] arr = new double[]{3.0, 4.0};
        Vector v = new Vector(arr);
        assertEquals(5.0, v.length(), DELTA);
    }

    @Test
    public void testProductScalar() {
        double[] arr = new double[]{3.0, 4.0};
        Vector v = new Vector(arr);
        Vector scalar = v.productScalar(2);
        assertEquals(2, scalar.getDimension());
        assertEquals(6.0, scalar.getComponent(1), DELTA);
        assertEquals(8.0, scalar.getComponent(2), DELTA);
    }

    @Test
    public void testSum() throws Exception {
        double[] u = new double[]{3.0, 4.0};
        double[] v = new double[]{5.0, 6.0};
        Vector uVec = new Vector(u);
        Vector vVec = new Vector(v);
        Vector rVec = App.sum(uVec, vVec);
        assertEquals(2, rVec.getDimension());
        assertEquals(8.0, rVec.getComponent(1), DELTA);
        assertEquals(10.0, rVec.getComponent(2), DELTA);
    }

    @Test
    public void testSumDifferentDimension() throws Exception {
        double[] u = new double[]{3.0, 4.0};
        double[] v = new double[]{5.0, 6.0, 7.0};
        Vector uVec = new Vector(u);
        Vector vVec = new Vector(v);
        try {
            Vector rVec = App.sum(uVec, vVec);
            fail("Sum of diffrent dimension vectors should throw exception");
        }
        catch (Exception e) {
            assertEquals((new Exception("Dimension error")).toString(), e.toString());
        }
    }

    @Test
    public void testInnerProduct() throws Exception{
        double[] u = new double[]{3.0, 4.0};
        double[] v = new double[]{5.0, 6.0};
        Vector uVec = new Vector(u);
        Vector vVec = new Vector(v);
        double result = App.innerProduct(uVec, vVec);
        assertEquals(39, result, DELTA);
    }

    @Test
    public void testInnerProductException() throws Exception{
        double[] u = new double[]{3.0, 4.0};
        double[] v = new double[]{5.0, 6.0, 7.0};
        Vector uVec = new Vector(u);
        Vector vVec = new Vector(v);
        try {
            double result = App.innerProduct(uVec, vVec);
        }
        catch (Exception e) {
            assertEquals((new Exception("Dimension Error")).toString(), e.toString());
        }
    }
}
