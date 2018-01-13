package edu.txstate.cs3320.geforce.data.driver;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;
import edu.txstate.cs3320.geforce.data.actor.Actor;
import edu.txstate.cs3320.geforce.data.customer.Customer;
import edu.txstate.cs3320.geforce.data.customer.custData;
import edu.txstate.cs3320.geforce.data.db.DAO;
import edu.txstate.cs3320.geforce.data.db.FilmDAO;
import edu.txstate.cs3320.geforce.data.film.Film;
import edu.txstate.cs3320.geforce.data.film.FilmCategory;

public class DriverMain {

	public static void main(String[] args) {
		
		java.util.List<Film> films ;
		java.util.List<Film> categoryFilms;
		java.util.List<Film> alphabeticalFilms;
		final int MAX_NEW = 8;
		
		FilmDAO filmDAO = new FilmDAO();
		films = filmDAO.findNewestFilms(MAX_NEW);
		
		//1
		System.out.println("Newest Movies available:");

		for(int i = 0; i < ((java.util.List<Film>) films).size(); i++)
		{
			System.out.print("ID: " + ((java.util.List<Film>) films).get(i).getFilmID() + "| ");
			System.out.print("Title: " + ((java.util.List<Film>) films).get(i).getTitle() + "| ");
			System.out.println("Release Year: " + ((java.util.List<Film>) films).get(i).getReleaseYear()+"|");
		}
		System.out.println("");

		//3
		films = (java.util.List<Film>) filmDAO.findFilmsByCategory(FilmCategory.COMEDY);
		System.out.println("Comedy: ");
		for(int i = 0; i < ((java.util.List<Film>) films).size(); i++)
		{
			System.out.print("ID: " + ((java.util.List<Film>) films).get(i).getFilmID() + "| ");
			System.out.print("Title: " + ((java.util.List<Film>) films).get(i).getTitle() + "| ");
			System.out.println("Category: " + FilmCategory.COMEDY + "|");
		}
		System.out.println("");

		//4
		alphabeticalFilms = filmDAO.findFilmsAlphabetically("A");
		
		System.out.println("Films starting with A");

		for(int i = 0; i < ((java.util.List<Film>) alphabeticalFilms).size(); i++)
		{
			System.out.print("ID: " + ((java.util.List<Film>) alphabeticalFilms).get(i).getFilmID() + "| ");
			System.out.println("Title: " + ((java.util.List<Film>) alphabeticalFilms).get(i).getTitle()+"|");
		}
		System.out.println("");
/*
 *  
 *  was not able to get working.
        // 5
        Film detailFilm = filmDAO.getFilmDetail(films.get(0));
        System.out.println("Title: " + detailFilm.getTitle());
        System.out.println("Release Year: " + detailFilm.getReleaseYear());
        System.out.println("Running Time: " + detailFilm.getLength());
        System.out.println("Rating: " + detailFilm.getRating());
        System.out.println("Category: " + detailFilm.getCategory());
        System.out.println("Description: " + detailFilm.getDescription());
        System.out.println("Actors:");
        List actors = (List) detailFilm.getActors();
        for (int i = 0; i < ((java.util.List<Film>) actors).size();i++) {
            String name  = ((java.util.List<Actor>) actors).get(i).getFirstName() + " " + ((java.util.List<Actor>) actors).get(i).getLastName();
            System.out.println(name);
        }
*/
		//7
        custData custData= new custData();
		Customer customer = new Customer();

		customer = custData.findCustomer("BETTY.WHITE@sakilacustomer.org", "password");
		System.out.println("ID: " + customer.getID());
		System.out.println("First Name: " + customer.getFirstName());
		System.out.println("Last Name: " + customer.getLastName());
		System.out.println("EmailAdress:  " + customer.getEmail());
		System.out.println("Password: " + customer.getPassword());
		
	}

}