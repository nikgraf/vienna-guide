type image = {
  url: string,
  attribution: string,
  attributionUrl: option(string),
};

type coordinates = {
  lat: float,
  lng: float,
};

type place = {
  id: string,
  name: string,
  description: string,
  image,
  phone: option(string),
  email: option(string),
  address: string,
  coordinates,
};

let places = [
  {
    id: "34a8c685-6088-4eed-bd58-3769b1a408ba",
    name: {j|Schönbrunn|j},
    description: {j|Schönbrunn Palace was the main summer residence of the Habsburg rulers, it is located in Hietzing, Vienna. The 1,441-room Baroque palace is one of the most important architectural, cultural, and historical monuments in the country. Since the mid-1950s it has been a major tourist attraction.|j},
    image: {
      url: "/assets/schoenbrunn.png",
      attribution: "CC BY-SA 2.0 by Christer van der Meeren",
      attributionUrl: Some("https://www.flickr.com/photos/cmeeren/"),
    },
    phone: Some("+43 1 81113239"),
    email: None,
    address: {j|Schönbrunner Schloßstraße 47, 1130 Vienna|j},
    coordinates: {
      lat: 48.186272,
      lng: 16.309719,
    },
  },
  {
    id: "675a1180-62cc-4518-b272-a0e1beeaf868",
    name: "Kaffemik",
    description: "Kaf|fe|mik noun, (greenlandic): 1. a traditional open-house get together where coffee is served; 2. a place for Europe's independent roasters in Vienna.",
    image: {
      url: "/assets/kaffemik.png",
      attribution: "Copyright by Konstantin Reyer",
      attributionUrl: Some("http://www.konstantinreyer.com/"),
    },
    phone: Some("+43 663 03046645"),
    email: None,
    address: "Zollergasse 5, 1070 Vienna",
    coordinates: {
      lat: 48.199153,
      lng: 16.351044,
    },
  },
  {
    id: "873da18c-4eb4-4cd1-8edf-d0bcc5776127",
    name: "Albertina",
    description: "The Albertina is a museum in the Innere Stadt of Vienna, Austria. It houses one of the largest and most important print rooms in the world with approximately 65,000 drawings and approximately 1 million old master prints, as well as more modern graphic works, photographs and architectural drawings.",
    image: {
      url: "/assets/albertina.png",
      attribution: "CC BY-NC-SA 2.0 by Lorenz Seidler",
      attributionUrl: Some("https://www.flickr.com/photos/eselat/"),
    },
    phone: None,
    email: None,
    address: "Albertinaplatz 1, 1010 Vienna",
    coordinates: {
      lat: 48.204062,
      lng: 16.368852,
    },
  },
];
