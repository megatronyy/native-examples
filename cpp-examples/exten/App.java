//java -agentpath:/home/wenbin/examples/native-examples/cpp-examples/exten/Jvmti_Evt_Ex.so  App
public class App {
    public static void main(String[] args) {
        System.out.println("Hello World!");

        try{
            throw new NullPointerException("QQQ");
        }catch (Exception e){

        }
    }
}
