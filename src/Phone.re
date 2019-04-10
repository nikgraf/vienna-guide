[@react.component]
let make = (~phone) => {
  switch (phone) {
  | None => <span /> /* return React.null */
  | Some(number) => <span> {React.string(number)} </span>
  };
};
