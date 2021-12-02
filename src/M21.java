import java.sql.*;

public class M21 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        Class.forName("com.mysql.cj.jdbc.Driver");
    //  For Oracle --> "oracle.jdbc.oracleDriver"
    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/M21","root","1234");
    Statement s = con.createStatement();
        ResultSet rs = s.executeQuery("select * from Emp");
        while (rs.next()){
            System.out.println(rs.getInt("1"));
        //  System.out.println(rs.getInt("id"));
            System.out.println(rs.getString(2));
        //  System.out.println(rs.getString("name));
        }
    }
}
