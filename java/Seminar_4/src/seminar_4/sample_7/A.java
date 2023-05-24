package seminar_4.sample_7;

//TODO: read https://stackoverflow.com/questions/69218585/what-are-sealed-classes-in-java-17
//  https://stackoverflow.com/questions/63860110/what-is-the-point-of-extending-a-sealed-class-with-a-non-sealed-class

public
abstract
sealed // sealed (англ.) - запечатанный...
class A permits B, C {
}

final class B extends A {}

sealed class C extends A permits D, F {}

final class D extends C {}
non-sealed class F extends C {}