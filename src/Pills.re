[@react.component]
let make = (~onClick) => {
  let filterList: list(Data.visibilityFilter) = [
    Data.All,
    Data.Museum,
    Data.Cafe,
  ];

  let elements =
    filterList
    ->Belt.List.map(filter => <Pill onClick name=filter />)
    ->Belt.List.toArray;

  <div> elements->React.array </div>;
};