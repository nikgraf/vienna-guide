[@react.component]
let make = (~onChange, ~searchTerm) => {
  <input
    type_="text"
    value=searchTerm
    placeholder="Search for places"
    onChange={event => onChange(ReactEvent.Form.target(event)##value)}
  />;
};