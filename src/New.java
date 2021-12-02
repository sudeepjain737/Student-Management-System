import java.awt.*;
import java.sql.*;
public class New {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/21m", "root", "");
            PreparedStatement ps = con.prepareStatement(("insert into Emp values(?,?)"));
            ps.setString(2,"sudeep");
            ps.setInt(1,1);
            ps.setInt(1,2);
            int i = ps.executeUpdate();
            System.out.println(i);
            PreparedStatement stmt=con.prepareStatement("select * from emp");
            ResultSet rs=stmt.executeQuery();
            while(rs.next()){
                System.out.println(rs.getInt(1)+" "+rs.getString(2));
            }
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
