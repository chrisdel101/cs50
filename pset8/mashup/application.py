import os
import re
from flask import Flask, jsonify, render_template, request

from cs50 import SQL
from helpers import lookup

# Configure application
app = Flask(__name__)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///mashup.db")


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
def index():
    """Render map"""
    return render_template("index.html")


# query db for postals and lookup
@app.route("/articles",methods=['GET', 'POST'])
def articles():
    """Look up articles for geo"""
    # get query string
    query = request.args.get('geo')
    print(query)
    results = lookup(query)
    # TODO
    return jsonify([results])

def queryType(query):
    # check if all digits - postal codes
    regex = r"([+])"
    if query.isdigit():
        return True
    else:
        return False


@app.route("/search",methods=['GET', 'POST'])
def search():
    """Search for places that match query"""
    query = request.args.get('q')
    print(query)
    # if all digits
    if queryType(query):
        # add wildcard
        query = query + '%'
        places = db.execute("SELECT * FROM places WHERE postal_code LIKE :q", q=query)
    else:
        # make wild
        query = query + '%'
        # place with wild card
        places = db.execute("SELECT place_name FROM places WHERE place_name LIKE :query LIMIT 2", query=query)
        placesList = []
        # make list of all places
        for place in places:
            eachPlace = place['place_name']
            placesList.append(eachPlace)
        # print(placesList)

        # states = db.execute("SELECT admin_code1 FROM places WHERE place_name=:place_name", place_name=place['place_name'])
        # print(place)
        # print(states)
    #   get postal

    # for state in states:
    #     obj = {
    #         'place':place,
    #         'state':state,
    #         'postal':
    #     }
    # make uniue list of places
        placesSet = set(placesList)
    # get postals for each place in one list
        postalsList = []
        for place in placesSet:
            # print(place)
            postals = db.execute("SELECT postal_code FROM places WHERE place_name=:place_name LIMIT 10", place_name=place)
            for postal in postals:
                postalsList.append(postal)

        # postalList is all postalcodes
        objs = []
        for postal in postalsList:
            # print(postal)
            obj = {
                'place':db.execute("SELECT place_name FROM places WHERE postal_code=:postal_code LIMIT 1", postal_code=postal['postal_code'])[0]['place_name'],
                'state':db.execute("SELECT admin_code1 FROM places WHERE postal_code=:postal_code LIMIT 1", postal_code=postal['postal_code'])[0]['admin_code1'],
                'postal':postal['postal_code'],
                'longitude': db.execute("SELECT longitude FROM places WHERE postal_code=:postal_code", postal_code=postal['postal_code'])[0]['longitude'],
                'latitude':db.execute("SELECT latitude FROM places WHERE postal_code=:postal_code", postal_code=postal['postal_code'])[0]['latitude']
            }
            objs.append(obj)
            # print(obj)
        # objs = []
        # for postal in postals:
        #     obj = {
        #         'place':db.execute("SELECT place_name FROM places WHERE postal_code=:postal_code", postal_code=postal['postal_code'])[0]['place_name'],
        #         'state':db.execute("SELECT admin_code1 FROM places WHERE postal_code=:postal_code", postal_code=postal['postal_code'])[0]['admin_code1'],
        #         'postal':postal['postal_code']
        #     }
        #     objs.append(obj)

        # print(objs)





        # regex = rr = r"(^[^\s]+)"
        # city = re.match(regex, query).group()
        # placeList = []
        # cities = db.execute("SELECT place_name FROM places WHERE place_name LIKE :query", query=query)
        # states = db.execute("SELECT admin_code1 FROM places WHERE place_name=:place_name", place_name=cities[0]['place_name'])

        # i = 0
        # # make city states list
        # cityStates = []
        # for city in cities:
        #     obj = {
        #         'city': city['place_name'],
        #         'state': states[i]['admin_code1'],
        #         # 'postal': db.execute("SELECT postal_code FROM places WHERE place_name=:place_name AND admin_code1=:admin_code1", place_name=city['place_name'], admin_code1=states[i]['admin_code1'])
        #     }
        #     i = i + 1
        #     cityStates.append(obj)
        # places = []
        # for place in cityStates:
        #         obj = {
        #       'city': place['city'],
        #       'state': place['state'],
        #     #   'postal': db.execute("SELECT postal_code FROM places WHERE place_name=:place_name AND admin_code1=:admin_code1", place_name=place['city'], admin_code1=place['state'])[0]['postal_code']
        #         }
        #         places.append(obj)

        # results = []
        # i = 0
        # for place in places:
        #     place['postal'] = db.execute("SELECT postal_code FROM places WHERE place_name=:place_name AND admin_code1=:admin_code1", place_name=place['city'], admin_code1=place['state'])
        #     results.append(place)
        #     i = i + 1
        # print('hello')
        # postals = []
        # for place in cityStates:
        #     postal = db.execute("SELECT postal_code FROM places WHERE place_name=:place_name AND admin_code1=:admin_code1", place_name=place['city'], admin_code1=place['state'])
        #     postals.append(postal)
        # store = {}
        # for postal in postals:
        #     for eachPostal in postal:
                # print(eachPostal)
    #     stateBool = False
    #     city = ""
    #     if not city:
    #         city = db.execute("SELECT place_name FROM places WHERE place_name LIKE :query", query=query)
    #     elif city:
    #         state = db.execute("SELECT admin_code1 FROM places WHERE place_name=:place_name", place_name=city[0]['place_name'])
    #     else:
    #         raise NameError('City name does not exist. Cannot get state')
    # # TODO
    #     if state:
    #         if not stateBool:
    #             postal = db.execute("SELECT postal_code FROM places WHERE place_name=:place_name AND admin_code1=:admin_code1", place_name=city[0]['place_name'], admin_code1=state[0]['admin_code1'])
    #             stateBool = True
    #     elif not state:
    #         raise NameError('State does not exist so cannot get postal.')
    #     else:
    #         print('Something happenend')
    # print(city)
    # print(state)
    # print(postal)
    # results = list((city, state, postal))
    if objs:
        return jsonify(objs)
    else:
        return 'No results'
#

@app.route("/update")
def update():
    """Find up to 10 places within view"""

    # Ensure parameters are present
    if not request.args.get("sw"):
        raise RuntimeError("missing sw")
    if not request.args.get("ne"):
        raise RuntimeError("missing ne")

    # Ensure parameters are in lat,lng format
    if not re.search("^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$", request.args.get("sw")):
        raise RuntimeError("invalid sw")
    if not re.search("^-?\d+(?:\.\d+)?,-?\d+(?:\.\d+)?$", request.args.get("ne")):
        raise RuntimeError("invalid ne")

    # Explode southwest corner into two variables
    sw_lat, sw_lng = map(float, request.args.get("sw").split(","))

    # Explode northeast corner into two variables
    ne_lat, ne_lng = map(float, request.args.get("ne").split(","))

    # Find 10 cities within view, pseudorandomly chosen if more within view
    if sw_lng <= ne_lng:

        # Doesn't cross the antimeridian
        rows = db.execute("""SELECT * FROM places
                          WHERE :sw_lat <= latitude AND latitude <= :ne_lat AND (:sw_lng <= longitude AND longitude <= :ne_lng)
                          GROUP BY country_code, place_name, admin_code1
                          ORDER BY RANDOM()
                          LIMIT 10""",
                          sw_lat=sw_lat, ne_lat=ne_lat, sw_lng=sw_lng, ne_lng=ne_lng)

    else:

        # Crosses the antimeridian
        rows = db.execute("""SELECT * FROM places
                          WHERE :sw_lat <= latitude AND latitude <= :ne_lat AND (:sw_lng <= longitude OR longitude <= :ne_lng)
                          GROUP BY country_code, place_name, admin_code1
                          ORDER BY RANDOM()
                          LIMIT 10""",
                          sw_lat=sw_lat, ne_lat=ne_lat, sw_lng=sw_lng, ne_lng=ne_lng)

    # Output places as JSON
    return jsonify(rows)
