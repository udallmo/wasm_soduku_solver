import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Table from '@material-ui/core/Table';
import TableBody from '@material-ui/core/TableBody';
import TableCell from '@material-ui/core/TableCell';
import TableContainer from '@material-ui/core/TableContainer';
import TableHead from '@material-ui/core/TableHead';
import TableRow from '@material-ui/core/TableRow';
import Paper from '@material-ui/core/Paper';

const useStyles = makeStyles({
  table: {
    minWidth: 300,
    maxWidth: 500,
    background: '#253746',
  },
});

function createData(name, calories, fat, carbs, protein) {
  return { name, calories, fat, carbs, protein };
}

const rows = [
    ['Runtime', '1ms'],
    ['Empty boxes', 8],
    ['Difficulty', 'EASY']
];

export default function DenseTable() {
  const classes = useStyles();

  return (
    <TableContainer component={Paper} style={{border: '1px solid #fafafa'}}>
      <Table className={classes.table} size="small" aria-label="a dense table" >
        <TableHead style={{borderBottom: '1px solid #fafafa'}}>
          <TableRow>
            <TableCell>
                <div style={{color: '#fafafa'}}>ANALYSIS</div>
            </TableCell>
          </TableRow>
        </TableHead>
        <TableBody>
          {rows.map((row) => (
            <TableRow key={row[0]}>
              <TableCell component="th" scope="row">
                <div style={{color: '#fafafa'}}>{row[0]}</div>
              </TableCell>
              <TableCell align="left">
                <div style={{color: '#fafafa'}}>{row[1]}</div>
              </TableCell>
            </TableRow>
          ))}
        </TableBody>
      </Table>
    </TableContainer>
  );
}
