[@react.component]
let make = (~name, ~onClick) => {
  let getNamesForVisibilityFilter = vf =>
    switch (vf) {
    | Data.Museum => "Museums"
    | Data.Cafe => "Cafes"
    | Data.All => "All places"
    };

  <button
    onClick={event => {
      ReactEvent.Mouse.preventDefault(event);

      onClick(name);
    }}>
    {name->getNamesForVisibilityFilter->React.string}
  </button>;
};