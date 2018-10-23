import java.lang.*;

public class Vector {
    private int _dim;
    private double[] _comp;

    public Vector(double[] arr) {
        this._dim = arr.length;
        this._comp = new double[this._dim];
        System.arraycopy(arr, 0, this._comp, 0, this._dim);
    }

    public int getDimension() { return this._dim; }
    public double getComponent(int n) { return this._comp[n-1]; }

    public double length() {
        double ans = 0.0;
        for (int i = 0; i < this._dim; ++i) {
            ans += this._comp[i] * this._comp[i];
        }
        return Math.sqrt(ans);
    }
    public Vector productScalar(int a) {
        double[] ans = new double[this._dim];
        for (int i = 0; i < this._dim; ++i) {
            ans[i] = a * this._comp[i];
        }
        return new Vector(ans);
    }
}
