[@react.component]
let make = (~name, ~placeType) => {
  let t =
    switch ((placeType: Data.placeType)) {
    | Data.Museum => "Museum"
    | Data.Cafe => "Cafe"
    };

  <p> {React.string(name ++ " / " ++ t)} </p>;
};