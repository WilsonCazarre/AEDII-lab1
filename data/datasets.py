import pandas

spotify_og = pandas.read_csv("./spotify.csv").sort_values("year")
spotify_og[["name", "genre", "year"]].to_csv("by_year.csv", index=False)
