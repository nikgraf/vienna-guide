/*  Data.getPlacesNames->Belt.Array.map(place => <li key=place> <Place name=place /> </li>)->React.array*/
[@react.component]
let make = () => {
  let (searchTerm, setSearchTerm) = React.useState(() => "");
  let (visibilityFilter, setVisibilityFilter) =
    React.useState(() => Data.All);

  let handleClickVisibilityFilter = selectedVisibilityFilter =>
    setVisibilityFilter(_ => selectedVisibilityFilter);

  <div>
    <Form onChange=setSearchTerm searchTerm />
    <Pills onClick=handleClickVisibilityFilter />
    <ul>
      {Data.places
       ->Data.searchPlacesByTerm(searchTerm)
       ->Data.searchPlacesByCategory(visibilityFilter)
       ->Belt.List.map(place =>
           <li key={place.id}>
             <Place name={place.name} placeType={place.placeType} />
           </li>
         )
       ->Belt.List.toArray
       ->React.array}
    </ul>
  </div>;
};