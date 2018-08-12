// Google Map
let map;

// Markers for map
let markers = [];

// Info window
let info = new google.maps.InfoWindow();


// Execute when the DOM is fully loaded
$(document).ready(function() {

    // Styles for map
    // https://developers.google.com/maps/documentation/javascript/styling
    let styles = [

        // Hide Google's labels
        {
            featureType: "all",
            elementType: "labels",
            stylers: [
                {visibility: "off"}
            ]
        },

        // Hide roads
        {
            featureType: "road",
            elementType: "geometry",
            stylers: [
                {visibility: "off"}
            ]
        }

    ];

    // Options for map
    // https://developers.google.com/maps/documentation/javascript/reference#MapOptions
    let options = {
        center: {lat: 42.3770, lng: -71.1256}, // Stanford, California
        disableDefaultUI: true,
        mapTypeId: google.maps.MapTypeId.ROADMAP,
        maxZoom: 14,
        panControl: true,
        styles: styles,
        zoom: 13,
        zoomControl: true
    };

    // Get DOM node in which map will be instantiated
    let canvas = $("#map-canvas").get(0);

    // Instantiate map
    map = new google.maps.Map(canvas, options);

    // Configure UI once Google Map is idle (i.e., loaded)
    google.maps.event.addListenerOnce(map, "idle", configure);


    document.querySelector('#my-button').addEventListener('click', () =>{
        console.log('remove')
        removeMarkers()
    })

});


// Add marker for place to map
function addMarker(place)
{
    console.log('add marker fired')
    // var myLatlng = {
    //     lat: place.longitude,
    //     lng: place.latitude

    // var myLatlng = new google.maps.LatLng(place.longitude,place.latitude);
    // }
    // var mapOptions = {
    //     zoom: 4,
    //     center: myLatlng
    // }
    // var map = new google.maps.Map(map, mapOptions)
    // map = new google.maps.Map(document.getElementById("map_canvas"),options);
    // console.log(map)

    // console.log('longitude', place.longitude)
    // console.log('latitude', place.latitude)


    var marker = new google.maps.Marker({
        position: { lat: place.latitude, lng: place.longitude },
        title: `${place.place_name}, ${place.admin_code1}`,
        label: {
            text: `${place.place_name}, ${place.admin_code1}`
        }
    })
    // console.log('map', map)
    // console.log('marker',marker)

    markers.push(marker)
    marker.setMap(map);

    var divs = $('.gmnoprint')

    marker.addListener('click', function() {
        console.log('click')
        let parameters = {
            geo: parseInt(place.postal_code)
        };
         $.getJSON("/articles", parameters, function(data, textStatus, jqXHR) {
        // Call typeahead's callback with search results (i.e., places)

        //     let ul = document.createElement('ul')
        //     data.forEach((article) => {
        //         console.log(typeof article)
        //       let li = document.createElement('li')
        //       let t = document.createTextNode(`${article.title}`)
        //       li.appendChild(t)
        //       ul.appendChild(li)
        //   })
        var objs = []
        for(var i=0; i < 1; i++){
            // strange array with all at index one
            let arr = data[i]
            for(var j=0;j < 5; j++){
                objs.push(arr[j])
            }
        }
        console.log('objs', objs)
        let ul = document.createElement('ul')
        ul.className += ' ul'

        let list = objs.map(obj => `<a href=${obj.link}><li>${obj.title}</li></a>`)
        .join('')
        console.log(list)
        ul.innerHTML = list
        // console.log(ul.innerHTML)
        // console.log(ul)

        // document.body.querySelector('.twitter-typeahead').appendChild(ul)
            showInfo(marker, list)

    //     var marker = new google.maps.Marker({
    //         animation: google.maps.Animation.DROP,
    //         label: {
    //             text: '!'
    // },
    //         map: myMap,
    //         position: myMapOptions.center
    //     });
        // ul = document.querySelector('.ul')
        // console.log(ul)

        // let lis = document.querySelectorAll('div#info > li')
        // let nodes = Array.from(lis).filter((li) => {
        // 	return (li.nodeName === 'LI')
        // })
        // console.log(nodes)


        // let divInfo = document.querySelector("div#info")
        // divInfo.remove()
        // let newUl = document.createElement('ul')
        // let list2 = nodes.map(node => newUl.appendChild(node))
        // newUl.innerHTML = list2
        // // ul.appendChild(list2)
        // divInfo.appendChild(newUl)
    });

  });
    // marker.addEventListener('click', () => {
    //     console.log('clicked')
    // })

}

// Configure application
function configure()
{
    // Update UI after map has been dragged
    google.maps.event.addListener(map, "dragend", function() {

        // If info window isn't open
        // http://stackoverflow.com/a/12410385
        if (!info.getMap || !info.getMap())
        {
            update();
        }
    });

    // Update UI after zoom level changes
    google.maps.event.addListener(map, "zoom_changed", function() {
        update();
    });



    // Configure typeahead
    $("#q").typeahead({
        highlight: false,
        minLength: 1
    },
    {
        display: function(suggestion) { return null },
        limit: 10,
        source: search,
        templates: {

            suggestion: Handlebars.compile(
                "<div>" +
                 "{{place}}, {{state}}, {{postal}}"  +
                "</div>"
            )
        }
    });

    // Re-center map after place is selected from drop-down
    $("#q").on("typeahead:selected", function(eventObject, suggestion, name) {
        console.log(eventObject)
        console.log(suggestion.latitude)
        map.setCenter({lat: parseFloat(suggestion.latitude), lng: parseFloat(suggestion.longitude)});

        // Update UI
        update();
    });

    // Hide info window when text box has focus
    $("#q").focus(function(eventData) {
        info.close();
    });

    // Re-enable ctrl- and right-clicking (and thus Inspect Element) on Google Map
    // https://chrome.google.com/webstore/detail/allow-right-click/hompjdfbfmmmgflfjdlnkohcplmboaeo?hl=en
    document.addEventListener("contextmenu", function(event) {
        event.returnValue = true;
        event.stopPropagation && event.stopPropagation();
        event.cancelBubble && event.cancelBubble();
    }, true);

    // Update UI
    update();

    // Give focus to text box
    $("#q").focus();
}


// Remove markers from map
function removeMarkers()
{
    console.log('remove markers called')
    function setMapOnAll(map) {
        for (var i = 0; i < markers.length; i++) {
          markers[i].setMap(map);
        }
      }
      setMapOnAll(null)
      markers = []
}

// Search database for typeahead's suggestions
function search(query, syncResults, asyncResults)
{
    // Get places matching query (asynchronously)
    let parameters = {
        q: query
    };
    $.getJSON("/search", parameters, function(data, textStatus, jqXHR) {
        // Call typeahead's callback with search results (i.e., places)

        asyncResults(data);
    });
}


// Show info window at marker with content
function showInfo(marker, content)
{
    // Start div
    let div = "<div id='info'>";
    if (typeof(content) == "undefined")
    {
        // http://www.ajaxload.info/
        div += "<img alt='loading' src='/static/ajax-loader.gif'/>";
    }
    else
    {
        div += content;
    }

    // End div
    div += "</div>";

    // Set info window's content
    info.setContent(div);

    // Open info window (if not already open)
    info.open(map, marker);
}


// Update UI's markers
function update()
{
    // Get map's bounds
    let bounds = map.getBounds();
    let ne = bounds.getNorthEast();
    let sw = bounds.getSouthWest();

    // Get places within bounds (asynchronously)
    let parameters = {
        ne: `${ne.lat()},${ne.lng()}`,
        q: $("#q").val(),
        sw: `${sw.lat()},${sw.lng()}`
    };
    $.getJSON("/update", parameters, function(data, textStatus, jqXHR) {
    console.log('update data',data)

       // Remove old markers from map
       removeMarkers();

       // Add new markers to map
       for (let i = 0; i < data.length; i++)
       {
           addMarker(data[i]);
       }
    });
};
