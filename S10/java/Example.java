
public class Example {

    class Base {
     public void f(double x) {
        System.out.println("Base::f(double x)");
     }
    }

    class Derived extends Base {
     public void f(int x) {
        System.out.println("Derived::f(int x)");
     }
    }

    public Example() {
	Derived d = new Derived();
	d.f(3.2);
	d.f(3);
    }

    public static void main(String[] args) {
	new Example();
    }
}
