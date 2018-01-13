package edu.txstate.cs3320.geforce.data.customer;

import java.sql.*;
import java.util.logging.Logger;

import com.mysql.jdbc.*;
import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;

import edu.txstate.cs3320.geforce.data.db.DAO;

public class custData extends DAO {

	private final static Logger LOGGER = Logger.getLogger(custData.class.getName());
	
	private static final int    CUSTOMER_ID_COLUMN          = 1;
	private static final int    CUSTOMER_FIRST_NAME_COLUMN  = 2;
	private static final int    CUSTOMER_LAST_NAME_COLUMN   = 3;
	private static final int    CUSTOMER_EMAIL_COLUMN       = 4;
	private static final int    CUSTOMER_PASSWORD_COLUMN    = 5;
	
	public Customer findCustomer(String emailAddress, String password)
	{
		Customer customer = null;
		Connection dbConnection = null;
		String queryString = "SELECT customer.customer_id, customer.first_name, customer.last_name, "
				+ "customer.email, customer.password FROM customer "
				+ "WHERE customer.email = '" + emailAddress + "'";
		try {
			dbConnection = (Connection) DAO.getDBConnection();
			Statement statement 	= (Statement) dbConnection.createStatement();
			ResultSet results       = statement.executeQuery(queryString);
			customer = buildResults (results);
			dbConnection.close();
		} catch (SQLException e) {
			closeQuietly(dbConnection);
			return null;
		}
		//checks if password is correct... if not returns null
		if(!(customer.getPassword().equals(password)))
			return null;
		
		return customer;
	}
	
	private Customer buildResults (ResultSet results) {
		Customer customer = null;
		try {
			while (results.next()) {
				int    id         = results.getInt   (CUSTOMER_ID_COLUMN);
				String firstName  = results.getString(CUSTOMER_FIRST_NAME_COLUMN);
				String lastName   = results.getString(CUSTOMER_LAST_NAME_COLUMN );
				String email      = results.getString(CUSTOMER_EMAIL_COLUMN );
				String password   = results.getString(CUSTOMER_PASSWORD_COLUMN);
				
				customer = new Customer(id, firstName, lastName, email, password);
			}
		} catch (SQLException e) {
			LOGGER.severe(e.toString());
		}
		return customer;
	}
	
	@Override
	public void save(Object anObject) throws SQLException {
		// This will be a no-op because we won't allow changes to films
	}
	
}