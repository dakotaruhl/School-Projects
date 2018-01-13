package edu.txstate.cs3320.geforce.data.actor;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.logging.Logger;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

import edu.txstate.cs3320.geforce.data.db.DAO;
import edu.txstate.cs3320.geforce.data.db.FilmDAO;
import edu.txstate.cs3320.geforce.data.film.Film;

public class actorData extends DAO {
	
	private final static Logger LOGGER = Logger.getLogger(FilmDAO.class.getName());
	
	public List findActorsInFilm (Film film) {
		ArrayList <Actor> actors  = new ArrayList <Actor> ();
		int filmID = film.getFilmID();
		Connection dbConnection = null;
		String queryString = "select actor_id, first_name, last_name from actor where actor_id in (select actor_id from film_actor where film_id = " + filmID + ")";
		try {
			dbConnection = (Connection) DAO.getDBConnection();
			Statement statement 	= (Statement) dbConnection.createStatement();
			ResultSet resultSet  = statement.executeQuery(queryString);
			//actors = buildResults (results);
			while (resultSet.next()) {
			int actorID = resultSet.getInt(1);
			String firstName = resultSet.getString(2);
			String lastName = resultSet.getString(3);
			Actor actor = new Actor(actorID,firstName,lastName);
			actors.add(actor);
			}
			dbConnection.close();
		} catch (SQLException e) {
			System.err.println("FilmDAO.findActorsInFilm: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		
		return (List) actors;
	}
	
	@Override
	public void save(Object anObject) throws SQLException {
		// This will be a no-op because we won't allow changes to films
	}
	

}