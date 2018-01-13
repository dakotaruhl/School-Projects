package edu.txstate.cs3320.geforce.data.db;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Logger;

import edu.txstate.cs3320.geforce.data.actor.Actor;
import edu.txstate.cs3320.geforce.data.actor.actorData;
import edu.txstate.cs3320.geforce.data.film.Film;
import edu.txstate.cs3320.geforce.data.film.FilmCategory;
import edu.txstate.cs3320.geforce.data.film.Film.FilmRating;
import edu.txstate.cs3320.geforce.data.helper.FilmFactory;

/**
 * @author Two
 *
 */
public class FilmDAO extends DAO {
	
	public FilmDAO () {
		
	}
	private final static Logger LOGGER = Logger.getLogger(FilmDAO.class.getName());
	
	private static final int    FILM_ID_COLUMN          = 1;
	private static final int    FILM_TITLE_COLUMN       = 2;
	private static final int    FILM_DESCRIPTION_COLUMN = 3;
	private static final int    FILM_LENGTH_COLUMN      = 4;
	private static final int    FILM_RATING_COLUMN      = 5;
	private static final int    FILM_RELEASE_YEAR       = 6;
	
	private static final String FILM_SELECT_STRING      = "SELECT film.film_id, film.title, film.description," +
			"film.length, film.rating, film.release_year";
	
	//1
	public List <Film> findNewestFilms (int maxNew) {
		List <Film> films = null;
		Connection dbConnection = null;
		String queryString = FILM_SELECT_STRING + " from film order by release_year desc limit " + maxNew;
		try {
			dbConnection = DAO.getDBConnection();
			Statement statement = dbConnection.createStatement();
			ResultSet results       = statement.executeQuery(queryString);
			films = buildResults (results);
			dbConnection.close();
		} catch (SQLException e) {
			System.err.println("FilmDAO.findNewestFilms: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		return films;
	}
	
	public List <Film> findFilmsByAttributes (String title, String description, int length, FilmRating rating) {
		String selectString = buildString (title, description, length, rating);
		List <Film> films = null;
		Connection dbConnection = null;
		try {
			dbConnection = DAO.getDBConnection();
			Statement statement 	= dbConnection.createStatement();
			ResultSet results       = statement.executeQuery(selectString);
			films = buildResults (results);
			dbConnection.close();
		} catch (SQLException e) {
			System.err.println("FilmDAO.findFilmsByAttributes: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		return films;
	}
	
	//3
	public List <Film> findFilmsByCategory(FilmCategory category)
	{
		List <Film> films = null;
		Connection dbConnection = null;
		String queryString = "SELECT film.film_id, film.title, film.description, film.length, film.rating, film.release_year " + 
	 			 "FROM film, film_category " + 
	 			 "WHERE film.film_id = film_category.film_id  AND  film_category.category_id = " + category.ordinal();
		try {
			dbConnection = DAO.getDBConnection();
			Statement statement 	= dbConnection.createStatement();
			ResultSet results       = statement.executeQuery(queryString);
			films = buildResults (results);
			dbConnection.close();
		} catch (SQLException e) {
			System.err.println("FilmDAO.findFilmsByAttributes: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		return films;
	}
	
	//4
	public List <Film> findFilmsAlphabetically(String firstCharacter)
	{
		List <Film> films = null;
		Connection dbConnection = null;
		String queryString = "SELECT film.film_id, film.title, film.description, film.release_year, film.length, film.rating " 
				+ "FROM film WHERE film.title LIKE '" + firstCharacter + "%'";
		try {
			dbConnection = DAO.getDBConnection();
			Statement statement 	= dbConnection.createStatement();
			ResultSet results       = statement.executeQuery(queryString);
			films = buildResults (results);
			dbConnection.close();
		} catch (SQLException e) {
			System.err.println("FilmDAO.findFilmsByAttributes: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		return films;
	}


	
	public Film getFilmDetail (Film film) {
		actorData actorData = new actorData();
		
		List <Actor> actors = (List<Actor>) actorData.findActorsInFilm(film);
		FilmCategory[] categories = FilmCategory.values();
		Connection dbConnection = null;
		int filmID = film.getFilmID();
		String queryString = "select category_id from film_category where film_id = " + filmID;
		String title = film.getTitle();
		String description = film.getDescription();
		String releaseYear = film.getReleaseYear();
		int length = film.getLength();
		Film detailedFilm = new Film(filmID,title,description,releaseYear,length,film.getRating());
		for (int i = 0;i < actors.size();i++) {
			detailedFilm.addActor(actors.get(i));
		}
		try {
			dbConnection = DAO.getDBConnection();
			Statement statement 	= dbConnection.createStatement();
			ResultSet results  = statement.executeQuery(queryString);
			results.next();
			int categoryID = results.getInt(1);
			detailedFilm.setCategory((categories[categoryID]).toString());
			
			dbConnection.close();
		}catch (SQLException e) {
			System.err.println("FilmDAO.getFilmDetail: " + e.toString());
			LOGGER.severe(e.toString());
			closeQuietly(dbConnection);
		}	
		
		return detailedFilm;
	}
	@Override
	public void save(Object anObject) throws SQLException {
		// This will be a no-op because we won't allow changes to films
	}
	

	

	private String buildString (String titleSubstring, String descriptionSubstring, int lengthMaximum, FilmRating ratingMaximum) {
		final String OPENING_QUOTED_WILD_CARD = "'%";
		final String CLOSING_QUOTED_WILD_CARD = "%'";
		
		int numberWhereClauses = 0;
		StringBuilder stringBuilder = new StringBuilder(FILM_SELECT_STRING);
		stringBuilder.append(" FROM ").append(getDBName()).append(".film").append(" WHERE ");
		
		if ((titleSubstring != null) && (titleSubstring != "")) {
			stringBuilder.append("title like ").
			append(OPENING_QUOTED_WILD_CARD).
			append(titleSubstring).
			append(CLOSING_QUOTED_WILD_CARD);
			numberWhereClauses++;
		}
		
		if ((descriptionSubstring != null) && (descriptionSubstring != "")) {
			if (numberWhereClauses != 0) {
				stringBuilder.append(" AND ");
			}
			stringBuilder.append("description like ").
			append(OPENING_QUOTED_WILD_CARD).
			append(descriptionSubstring).
			append(CLOSING_QUOTED_WILD_CARD);
			numberWhereClauses++;
		}
		
		// create the clause to select any movie that has a running time <= lengthMaximum
		if (lengthMaximum > 0)  {
			if (numberWhereClauses != 0) {
				stringBuilder.append(" AND ");
			}
			stringBuilder.append("length <= ").append(String.valueOf(lengthMaximum));
			numberWhereClauses++;
		}
		

		if ((ratingMaximum != null) && (ratingMaximum != FilmRating.UR)){
			if (numberWhereClauses != 0) {
				stringBuilder.append(" AND ");
			}
			int databaseRatingOrdinal = ratingMaximum.ordinal() + 1;
			stringBuilder.append("rating <= ").append(databaseRatingOrdinal);
			numberWhereClauses++;
		}
		String selectString = stringBuilder.toString();
		LOGGER.info(selectString);
		return selectString;
	}

	private List<Film> buildResults (ResultSet results) {
		ArrayList <Film> films  = new ArrayList <Film> ();
		FilmFactory filmFactory = new FilmFactory ();
		try {
			while (results.next()) {
				int    id             =  results.getInt   (FILM_ID_COLUMN );
				String filmTitle       = results.getString(FILM_TITLE_COLUMN );
				String filmDescription = results.getString(FILM_DESCRIPTION_COLUMN);
				int    filmLength      = results.getInt   (FILM_LENGTH_COLUMN);
				String filmRating      = results.getString(FILM_RATING_COLUMN);
				String release_year    = results.getString(FILM_RELEASE_YEAR);
				Film film = filmFactory.makeFilm(Integer.toString(id), filmTitle, filmDescription, release_year, Integer.toString(filmLength), filmRating);
				films.add(film);
			}
		} catch (SQLException e) {
			LOGGER.severe(e.toString());
		}
		return films;
	}
}