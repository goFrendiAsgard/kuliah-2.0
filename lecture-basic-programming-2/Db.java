
//STEP 1. Import required packages
import java.sql.*;

public class Db {
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
    static final String DB_URL = "jdbc:mysql://0.0.0.0:3306/pd2b";

    //  Database credentials
    static final String USER = "root";
    static final String PASS = "toor";
    
    public static void main(String[] args) throws Exception {
        // STEP 2: Register JDBC driver
        // Class.forName(JDBC_DRIVER);

        // STEP 3: Open a connection
        Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
        Statement stmt = conn.createStatement();
        
        // EXAMPLE: Insert
        stmt.execute("INSERT INTO mahasiswa(nama, prodi) VALUES('contoh', 'contoh')");
        
        // EXAMPLE: Select        
        ResultSet rs = stmt.executeQuery("SELECT * FROM mahasiswa");
        while(rs.next()) {
            System.out.println(
                rs.getInt("id") + " " +
                rs.getString("nama") + " " +
                rs.getString("prodi")
            );
        }
        
        // STEP 4: Close Connection
        conn.close();
    }
    
}
