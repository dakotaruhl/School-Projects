package edu.txstate.cs3320.geforce.data.strategy;

import edu.txstate.cs3320.geforce.data.film.Film;

public abstract class SelectorStrategy  {
	public abstract boolean meetsCriteria (Film searchCandidate);
}