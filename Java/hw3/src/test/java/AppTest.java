/*
 * This Java source file was generated by the Gradle 'init' task.
 */
import org.junit.Test;
import static org.junit.Assert.*;

public class AppTest {
    @Test public void testAppHasAGreeting() {
        App classUnderTest = new App();
        assertNotNull("app should have a greeting", classUnderTest.getGreeting());
    }
    @Test public void testAdd() {
        assertEquals(2, 1+1);
        assertEquals(-2, -1+(-1));
    }
    @Test public void testSubstract() {
        assertEquals(0, 1-1);
        assertEquals(1, -1-(-2));
    }
    @Test public void testMultiply() {
        assertEquals(2, 1*2);
        assertEquals(2, -1*(-2));
    }
    @Test public void testMax() {
        assertEquals(2, App.max(1, 2));
    }
    @Test public void testMin() {
        assertEquals(1, App.min(1, 2));
    }
    @Test public void testAddVector() {
        assertArrayEquals(new int[] {2, 1}, App.addVector(new int[]{1, 0}, new int[]{1, 1}));
    }
    @Test public void testAddThreeDimension() {
        assertArrayEquals(new int[] {1, 2, 1}, App.addVector(new int[]{1, 1, 0}, new int[]{0, 1, 1}));
    }
    @Test public void testAddException() {
        assertNull(App.addVector(new int[]{1, 0}, new int[]{1, 1, 0}));
    }
    @Test public void testInnerProduct() throws Exception{
        assertEquals(1, App.innerProduct(new int[]{1, 0}, new int[]{1, 1}));
    }
    @Test public void testInnerProductThreeDimension() throws Exception{
        assertEquals(2, App.innerProduct(new int[]{1, 1, 0}, new int[]{1, 1, 1})); 
    }
    @Test (expected = Exception.class) 
    public void testInnerProductException() throws Exception {
        App.innerProduct(new int[] {1, 0}, new int[] {1, 1, 0}); 
    }

    @Test 
    public void testVectorFunction() throws Exception {
        int[] u = new int[]{1, 0}; 
        int[] v = new int[]{1, 1};
        int[] w = new int[]{2, 3}; 
        assertEquals(App.innerProduct(u, App.addVector(v, w)), 
           App.innerProduct(u, v) + App.innerProduct(u, w)); 
    }
}